#include <stdio.h>
#include <stdlib.h>

 //��l�m����IP  
 
int IP_Table[64] = {  57,49,41,33,25,17, 9,1,  
                      59,51,43,35,27,19,11,3,  
                      61,53,45,37,29,21,13,5,  
                      63,55,47,39,31,23,15,7,  
                      56,48,40,32,24,16, 8,0,  
                      58,50,42,34,26,18,10,2,  
                      60,52,44,36,28,20,12,4,  
                      62,54,46,38,30,22,14,6};   
//�f��l�m����IP^-1  
int IP_1_Table[64] = {39,7,47,15,55,23,63,31,  
           38,6,46,14,54,22,62,30,  
           37,5,45,13,53,21,61,29,  
           36,4,44,12,52,20,60,28,  
           35,3,43,11,51,19,59,27,  
           34,2,42,10,50,18,58,26,  
           33,1,41,9,49,17,57,25,  
           32,0,40,8,48,16,56,24};  
  
//�X�R�m����E  
int E_Table[48] = {31, 0, 1, 2, 3, 4,  
                  3,  4, 5, 6, 7, 8,  
                  7,  8,9,10,11,12,  
                  11,12,13,14,15,16,  
                  15,16,17,18,19,20,  
                  19,20,21,22,23,24,  
                  23,24,25,26,27,28,  
                  27,28,29,30,31, 0};  
  
//�m�����P  
int P_Table[32] = {15,6,19,20,28,11,27,16,  
                  0,14,22,25,4,17,30,9,  
                  1,7,23,13,31,26,2,8,  
                  18,12,29,5,21,10,3,24};  
  
//S��  
int S[8][4][16] =//S1  
            {{{14,4,13,1,2,15,11,8,3,10,6,12,5,9,0,7},  
              {0,15,7,4,14,2,13,1,10,6,12,11,9,5,3,8},  
                {4,1,14,8,13,6,2,11,15,12,9,7,3,10,5,0},  
                {15,12,8,2,4,9,1,7,5,11,3,14,10,0,6,13}},  
                //S2  
              {{15,1,8,14,6,11,3,4,9,7,2,13,12,0,5,10},  
              {3,13,4,7,15,2,8,14,12,0,1,10,6,9,11,5},  
              {0,14,7,11,10,4,13,1,5,8,12,6,9,3,2,15},  
              {13,8,10,1,3,15,4,2,11,6,7,12,0,5,14,9}},  
              //S3  
              {{10,0,9,14,6,3,15,5,1,13,12,7,11,4,2,8},  
              {13,7,0,9,3,4,6,10,2,8,5,14,12,11,15,1},  
                {13,6,4,9,8,15,3,0,11,1,2,12,5,10,14,7},  
              {1,10,13,0,6,9,8,7,4,15,14,3,11,5,2,12}},  
              //S4  
              {{7,13,14,3,0,6,9,10,1,2,8,5,11,12,4,15},  
              {13,8,11,5,6,15,0,3,4,7,2,12,1,10,14,9},  
              {10,6,9,0,12,11,7,13,15,1,3,14,5,2,8,4},  
              {3,15,0,6,10,1,13,8,9,4,5,11,12,7,2,14}},  
              //S5  
              {{2,12,4,1,7,10,11,6,8,5,3,15,13,0,14,9},  
              {14,11,2,12,4,7,13,1,5,0,15,10,3,9,8,6},  
              {4,2,1,11,10,13,7,8,15,9,12,5,6,3,0,14},  
              {11,8,12,7,1,14,2,13,6,15,0,9,10,4,5,3}},  
              //S6  
              {{12,1,10,15,9,2,6,8,0,13,3,4,14,7,5,11},  
              {10,15,4,2,7,12,9,5,6,1,13,14,0,11,3,8},  
              {9,14,15,5,2,8,12,3,7,0,4,10,1,13,11,6},  
              {4,3,2,12,9,5,15,10,11,14,1,7,6,0,8,13}},  
              //S7  
              {{4,11,2,14,15,0,8,13,3,12,9,7,5,10,6,1},  
              {13,0,11,7,4,9,1,10,14,3,5,12,2,15,8,6},  
              {1,4,11,13,12,3,7,14,10,15,6,8,0,5,9,2},  
              {6,11,13,8,1,4,10,7,9,5,0,15,14,2,3,12}},  
              //S8  
              {{13,2,8,4,6,15,11,1,10,9,3,14,5,0,12,7},  
              {1,15,13,8,10,3,7,4,12,5,6,11,0,14,9,2},  
              {7,11,4,1,9,12,14,2,0,6,10,13,15,3,5,8},  
              {2,1,14,7,4,10,8,13,15,12,9,0,3,5,6,11}}};  
//�m�����1  
int PC_1[56] = {56,48,40,32,24,16,8,  
              0,57,49,41,33,25,17,  
              9,1,58,50,42,34,26,  
              18,10,2,59,51,43,35,  
              62,54,46,38,30,22,14,  
              6,61,53,45,37,29,21,  
              13,5,60,52,44,36,28,  
              20,12,4,27,19,11,3};  
  
//�m�����2  
int PC_2[48] = {13,16,10,23, 0, 4,
                 2,27,14, 5,20, 9,
                22,18,11, 3,25, 7,
                15, 6,26,19,12, 1,
                40,51,30,36,46,54,
                29,39,50,44,32,47,
                43,48,38,55,33,52,
                45,41,49,35,28,31};  
  
//�索�����ƪ��W�w  
int MOVE_TIMES[16] = {1,1,2,2,2,2,2,2,1,2,2,2,2,2,2,1};  


typedef unsigned char char8[8]; 
typedef unsigned char char64[64]; 
typedef unsigned char char56[56]; 
typedef unsigned char char48[48]; 

typedef unsigned char char32[32];

typedef unsigned char subkey[48]; 
typedef subkey subkeySet[16];
  






void GetPlainText( char8 charArray, FILE *fp ) ;
void GetKEY( char8 charArray, FILE *fp ) ;

void Extend8To64( char64 block64,char8 block8) ;


void DES( char64 block,subkeySet keySet ) ;
void DESDecoding( char64 block,subkeySet keySet ) ;

void DeExtend64To8( char64 block64,char8 block8 ) ;

void GenerateSubKeySet( subkeySet subkeySet1 ,char64 key ) ;



void DES_PC1_Transform(char64 key, char56 temp) ;
void DES_PC2_Transform(char56 key, char48 temp );

int DES_ROL( char56 data, int time) ;


void DES_IP_Transform(char64 data) ;
void DES_IP_1_Transform(char64 data); 


void RightExtend( char64 block,char48 copyRight) ;



void DES_E_Transform( char48 data);  
        
void DES_SBOX(char48 data);  
        
void DES_P_Transform(char48 data);  
        
void DES_XOR(char48 R,char48 L, int count ); 

void DES_Swap(char32 left, char32 right) ;


/* �Ĥ@�� C �{��  (hello.c) */
main() {
   printf("hello, This is 3-DES homework \n");
   
   FILE *fPtr;   /*�ŧiFILE��ƫ��A�� ����*/ 
   FILE *fKey1;   /*�ŧiFILE��ƫ��A�� ����*/ 
   FILE *fKey2;   /*�ŧiFILE��ƫ��A�� ����*/ 
   FILE *fKey3;   /*�ŧiFILE��ƫ��A�� ����*/    
   
   char fname[] = "plainText.txt" ;
   char fKeyName1[] = "key1.txt" ;
   char fKeyName2[] = "key2.txt" ;
   char fKeyName3[] = "key3.txt" ;
   
   
   
   printf("�ڷ|�}�ҭ��:%s\n\n",fname);
   fPtr = fopen(fname,"r");  /* fopen function , �����ɮצW�١A�M�g�J�覡 */
   
   printf("�ڷ|�}��KEY1:%s\n\n",fKeyName1);
   fKey1 = fopen(fKeyName1,"r");  /* fopen function , �����ɮצW�١A�M�g�J�覡 */
   
   printf("�ڷ|�}��KEY2:%s\n\n",fKeyName2);
   fKey2 = fopen(fKeyName2,"r");  /* fopen function , �����ɮצW�١A�M�g�J�覡 */
   
   printf("�ڷ|�}��KEY3:%s\n\n",fKeyName3);
   fKey3 = fopen(fKeyName3,"r");  /* fopen function , �����ɮצW�١A�M�g�J�覡 */
   
   char8 block ;
   char8 key1 ;
   char8 key2 ;
   char8 key3 ;
   
   GetPlainText( block, fPtr ) ;
   GetKEY( key1, fKey1 ) ;
   GetKEY( key2, fKey2 ) ;
   GetKEY( key3, fKey3 ) ;
 

  //fprintf(fPtr, " �n�g�J���r�� ");   /* �N�r��g�J�ɮ� */

   fclose(fPtr); /* �����ɮ� */ 
   fclose(fKey1); /* �����ɮ� */ 
   fclose(fKey2); /* �����ɮ� */ 
   fclose(fKey3); /* �����ɮ� */ 
   
   
  
   
   
   char64 block64 ;
   char64 key64_1 ;
   char64 key64_2 ;
   char64 key64_3 ;
   
   
   char8  chiperText8 ;
   
   
   printf(  "�����BLOCK64:\n" );
   
   /* ��0x01�z���_ ��12345678�[�K �����G 
   block[0] = 0x62 ;
   block[1] = 0xdd ;
   block[2] = 0x8e ;
   block[3] = 0x4a ;
   block[4] = 0x61 ;
   block[5] = 0x4e ;
   block[6] = 0x1a ;
   block[7] = 0xf9 ;
   */
   
   Extend8To64( block64,block ) ;
   
   
   printf(  "�K�_1��BLOCK64:\n" );
   
   //  �o�O�z���_������ 
   // for ( int i=0 ; i < 8 ; i++ ) key1[i] = 0x01;
   
   
   Extend8To64( key64_1,key1 ) ;
   
   
   subkeySet subkeySet1 ;
   
   GenerateSubKeySet(subkeySet1 , key64_1 ) ;
   
   //////////////////////////////////////////////////////////////////////
   
   printf(  "�K�_2��BLOCK64:\n" );
   
   //  �o�O�z���_������ 
   for ( int i=0 ; i < 8 ; i++ ) key2[i] = 0x01;
   
   
   Extend8To64( key64_2,key2 ) ;
   
   
   subkeySet subkeySet2 ;
   
   GenerateSubKeySet(subkeySet2 , key64_2 ) ;
   
   ////////////////////////////////////////////////////////////
   
   printf(  "�K�_3��BLOCK64:\n" );
   
   // �o�O�z���_������ 
   for ( int i=0 ; i < 8 ; i++ ) key3[i] = 0x01;
   
   
   Extend8To64( key64_3,key3 ) ;
   
   
   subkeySet subkeySet3 ;
   
   GenerateSubKeySet(subkeySet3 , key64_3 ) ;
   
   
   
   
   DES( block64,subkeySet1 ) ;
   //DESDecoding( block64,subkeySet2 ) ;
   //DES( block64,subkeySet3 ) ;
   
   
   // block64 �|�ܦ��K�� 
   DeExtend64To8( block64,chiperText8 ) ;
   
   
   
   
   
   
   
 
 
   system("pause");
   
   return( 0 );
}


void GetPlainText( char8 charArray, FILE *fp ) {
     for ( int i = 0 ; i <=7  ; i ++ ) {
       charArray[i] = 0x00 ;
     } // for
     
     for ( int i = 0 ; i < 8 ; i++ ) fscanf(fp,"%c", &charArray[i] );
     
     printf(  "���O�o��:\n\"" );
     
     
     for ( int i = 0 ; i <=7  ; i ++ ) {
       printf(  "%c",charArray[i] );
     } // for
	 
     printf(  "\"\n" );
     
}  // void GetChar( char charArray[], FILE fileName ) { end

void GetKEY( char8 charArray, FILE *fp )  {
     for ( int i = 0 ; i <=7  ; i ++ ) {
       charArray[i] = 0x00 ;
     } // for
     
     for ( int i = 0 ; i < 8 ; i++ ) fscanf(fp,"%c", &charArray[i] );
     
     printf(  "KEY�O�o��:\n\"" );
     
     
     for ( int i = 0 ; i <=7  ; i ++ ) {
       printf(  "%c",charArray[i] );
     } // for
	 
     printf(  "\"\n" );
     
}  // void GetChar( char charArray[], FILE fileName ) { end


void Extend8To64( char64 block64,char8 block8) {
     
     
     
     
     for ( int base = 0 ; base < 8 ; base ++ ) {
       
       for ( int i = 0 ; i < 8 ; i ++ ) {
           
           block64[base*8+i]=((( block8[base]<< i )& 0x80 )>>7);
           
           // ���n�� ���n�� �@���ɦb������ �o�O�줸���޿�B�� 
           
       } // for 
       
       
     } // for
     
     
     
     
     printf(  "����==block64���o��==����\n" );
     
     for ( int i =0  ; i <= 63   ; i ++ ) {
       if ( block64[i] == 0x00 ) printf( "0" );
       else if ( block64[i] == 0x01 ) printf( "1" );
       else printf( "\n%d:is a error\n",i );
       
       if ( (i+1)%4 == 0 ) printf(  " " );
       if ( (i+1)%8 == 0 ) printf(  "\n" );
     } // for
     
     printf(  "����==block64���o��==����\n" );
     
     
     
     
     
     
     
} // void 




void DeExtend64To8( char64 block64,char8 block8 ) {
     printf(  "����==block64�K����o��==����\n" );
     
     for ( int i =0  ; i <= 63   ; i ++ ) {
       if ( block64[i] == 0x00 ) printf( "0" );
       else if ( block64[i] == 0x01 ) printf( "1" );
       else printf( "\n%d:is a error\n",i );
       
       if ( (i+1)%4 == 0 ) printf(  " " );
       if ( (i+1)%8 == 0 ) printf(  "\n" );
     } // for
     
     printf(  "����==block64�K����o��==����\n" );
     
     
     
     for ( int base = 0 ; base < 8 ; base ++ ) {
         
         block8[base] = 0x00;
         
       
       
       for ( int i = 0 ; i < 8 ; i ++ ) {
           
           block8[base] = ( ( block64[8*base+i] << (7-i) ) ^ block8[base] ); 
           
           // ���n�� ���n�� �@���ɦb������ �o�O�줸���޿�B�� 
           
       } // for 
       
       
     } // for
     
     
     
     
     printf(  "����==block64�K�媺16�i���ܪk���o��==����\n" );
     for ( int i = 0 ; i < 8 ; i++ ) {
         printf(  "0x%x\n", block8[i] );
     } // for
     printf(  "����==block64�K�媺16�i���ܪk���o��==����\n" );
     
     
     
     printf(  "�p�G�A������� �ڥi�H���A�ݦr����o��:\n" );
     for ( int i = 0 ; i < 8 ; i++ ) {
         printf(  "%c", block8[i] );
     } // for
     
     printf(  "\nMaybe�������u�ƦC����n�ݧa?:\n" );
      for ( int i = 0 ; i < 8 ; i++ ) {
         printf(  "%c\n", block8[i] );
     } // for
     
     printf(  "\n" );
     
     
}  // void DeExtend64To8( char64 block64,char8 block8 ) ;


void DES( char64 block,subkeySet keySet ) {
          
          /*
          for ( int j = 0 ; j < 16 ; j++ ) {
              printf(  "����==��%d��KEY���o��==����\n" , j);
              for ( int i = 0 ; i < 48 ; i++ ) {
                  if ( keySet[j][i] == 0x00 ) printf( "0" );
                  else if ( keySet[j][i] == 0x01 ) printf( "1" );
                  else printf( "\n(%d,%d):is a error\n",j,i );
                  
                  if ( (i+1)%4 == 0 ) printf(  " " );
                  if ( (i+1)%8 == 0 ) printf(  "\n" );
              } // for
              printf(  "����==��%d��KEY���o��==����\n" ,j );
          } // for 
          */
          
          
          DES_IP_Transform(block);  // ���i�� IP �m�� 
          
          char48 copyRight;  
          
          
          
          for( int i = 0; i < 16; i++){         
              RightExtend( block,copyRight) ;
        
              DES_E_Transform(copyRight);  
        
              DES_XOR(copyRight,keySet[i],48);   
        
              DES_SBOX(copyRight);  
        
              DES_P_Transform(copyRight);  
        
              DES_XOR(block,copyRight,32);  
             if( i != 15){  
            
               DES_Swap(block,block+32);  
             } // if  
           }  // for
          
          
          DES_IP_1_Transform(block);  
          // Bit64ToChar8(block,cipherBlock);  
          
          
          return ;
} // char64ptr DES( char64 block,char64 key ) end


void DESDecoding( char64 block,subkeySet keySet )  {
     
     
     //�[�K��ѱK�򥻤W�O�@�@�˪���
     //���L�ѱKKEY�O�q��16��}�l�����1�� 
    
    char48 copyRight;  
    
  
    DES_IP_Transform(block);  // ���i�� IP �m�� 
      
    
    for(int i = 15 ; i >= 0; i--){        
        RightExtend( block,copyRight) ;
        
        DES_E_Transform(copyRight);  
       
        DES_XOR(copyRight,keySet[i],48);       
        
        DES_SBOX(copyRight);  
       
        DES_P_Transform(copyRight);       
        
        DES_XOR(block,copyRight,32);  
        if( i != 0){  
            
            DES_Swap(block,block+32);  
        }  
    }  
    
    DES_IP_1_Transform(block);  
    
    return ;  
     
     
     
     
     
     
} // void DESDecoding( char64 block,subkeySet keySet ) 



void GenerateSubKeySet( subkeySet subkeySet1 ,char64 key ) {
     
     char56 temp ;
     
     
     
     
     
     
     DES_PC1_Transform( key, temp) ;
     
     for( int i = 0; i < 16; i++){ //�`��16�� �ͥX16��SUBKEY 
        DES_ROL(temp,MOVE_TIMES[i]);//�ھڴ`���� �`������  
        DES_PC2_Transform(temp,subkeySet1[i]);//PC2�m��  
    }  
    
    return ;  
     
             
} // void GenerateSubKeySet( subkeySet subkeySet1 ,char64 key ) {








//�K�_�m��1  
void DES_PC1_Transform(char64 key, char56 temp) {  
    int i;      
    for(i = 0; i < 56; i++){  
        temp[i] = key[PC_1[i]];  
    }  
    return;  
}  


//�K�_�m��2
void DES_PC2_Transform(char56 key, char48 temp ){  
    int i;  
    for(i = 0; i < 48; i++){  
        temp[i] = key[PC_2[i]];  
    }  
    return ;  
} 


//�`������  
int DES_ROL(char56 data, int time){     
    char56 temp;  
    
    
    for ( int j = 0 ; j < time ; j++ ) {
        
        
        char temp1 = data[ 0] ;
        char temp2 = data[28] ;
        
        
        for ( int i = 0 ; i < 28 ; i ++ ) {
            data[i] = data[i+1] ;
        } // for
        data[27] = temp1 ;
        
        for ( int i = 28 ; i < 56 ; i ++ ) {
            data[i] = data[i+1] ;
        } // for
        data[55] = temp2 ;
        
        
        
    }  // for      
  
    return 0;  
}




//IP�m�� 
void DES_IP_Transform(char64 data){  
     
    char64 temp;  
    for( int i = 0; i < 64; i++){  
        temp[i] = data[IP_Table[i]];  
    }  
    
    
    for( int i = 0; i < 64; i++){  
        data[i] = temp[i] ;
    } 
    
    
    return ;  
}  





void RightExtend( char64 block,char48 copyRight) {
     
     for ( int i = 0 ; i < 48 ; i ++ ) {
         if ( i < 32 ) copyRight[i] = block[32+i];
         else copyRight[i] = 0x00 ;
     } // for 
     
     
     
     
}

//IP�f�m�� IP^-1 
void DES_IP_1_Transform( char64 data){  
    int cnt;  
    char64 temp;  
    for(cnt = 0; cnt < 64; cnt++){  
        temp[cnt] = data[IP_1_Table[cnt]];  
    }  
    
    for( int i = 0; i < 64; i++){  
        data[i] = temp[i] ;
    } 
    return ;
}  
  
//�X�i�m��  
void DES_E_Transform(char48 data){  
    int cnt;  
    char48 temp;  
    for(cnt = 0; cnt < 48; cnt++){  
        temp[cnt] = data[E_Table[cnt]];  
    }     
    
    for( int i = 0; i < 48; i++){  
        data[i] = temp[i] ;
    } 
    return ;  
}  
  
//P�m�� 
void DES_P_Transform(char32 data){  
    int cnt;  
    char32 temp;  
    for(cnt = 0; cnt < 32; cnt++){  
        temp[cnt] = data[P_Table[cnt]];  
    }     
    
    for( int i = 0; i < 32; i++){  
        data[i] = temp[i] ;
    } 
    return ;  
}  
  
//XOR 
void DES_XOR(char48 R, char48 L ,int count){  
    int cnt;  
    for(cnt = 0; cnt < count; cnt++){  
        R[cnt] ^= L[cnt];  
    }  
    return ;  
}  
  
//S���m�� 
void DES_SBOX(char48 data){  
    int cnt;  
    int line,row,output;  
    int cur1,cur2;  
    for(cnt = 0; cnt < 8; cnt++){  
        cur1 = cnt*6;  
        cur2 = cnt<<2;  
          
        //?��bS���������O�C  
        line = (data[cur1]<<1) + data[cur1+5];  
        row = (data[cur1+1]<<3) + (data[cur1+2]<<2)  
            + (data[cur1+3]<<1) + data[cur1+4];  
        output = S[cnt][line][row];  
  
        //��?2?��  
        data[cur2] = (output&0X08)>>3;  
        data[cur2+1] = (output&0X04)>>2;  
        data[cur2+2] = (output&0X02)>>1;  
        data[cur2+3] = output&0x01;  
    }     
    return ;  
}  


//�洫 
void DES_Swap(char32 left, char32 right){  
    char32 temp ;
    
    
    for( int i = 0; i < 32; i++){  
        temp[i] = left[i];
    } 
    for( int i = 0; i < 32; i++){  
        left[i] = right[i];
    } 
    for( int i = 0; i < 32; i++){  
        right[i] = temp[i];
    } 
    
    return ;  
}  




