#include <stdio.h>
#include <stdlib.h>

 //初始置換表IP  
 
int IP_Table[64] = {  57,49,41,33,25,17, 9,1,  
                      59,51,43,35,27,19,11,3,  
                      61,53,45,37,29,21,13,5,  
                      63,55,47,39,31,23,15,7,  
                      56,48,40,32,24,16, 8,0,  
                      58,50,42,34,26,18,10,2,  
                      60,52,44,36,28,20,12,4,  
                      62,54,46,38,30,22,14,6};   
//逆初始置換表IP^-1  
int IP_1_Table[64] = {39,7,47,15,55,23,63,31,  
           38,6,46,14,54,22,62,30,  
           37,5,45,13,53,21,61,29,  
           36,4,44,12,52,20,60,28,  
           35,3,43,11,51,19,59,27,  
           34,2,42,10,50,18,58,26,  
           33,1,41,9,49,17,57,25,  
           32,0,40,8,48,16,56,24};  
  
//擴充置換表E  
int E_Table[48] = {31, 0, 1, 2, 3, 4,  
                  3,  4, 5, 6, 7, 8,  
                  7,  8,9,10,11,12,  
                  11,12,13,14,15,16,  
                  15,16,17,18,19,20,  
                  19,20,21,22,23,24,  
                  23,24,25,26,27,28,  
                  27,28,29,30,31, 0};  
  
//置換函數P  
int P_Table[32] = {15,6,19,20,28,11,27,16,  
                  0,14,22,25,4,17,30,9,  
                  1,7,23,13,31,26,2,8,  
                  18,12,29,5,21,10,3,24};  
  
//S盒  
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
//置換選擇1  
int PC_1[56] = {56,48,40,32,24,16,8,  
              0,57,49,41,33,25,17,  
              9,1,58,50,42,34,26,  
              18,10,2,59,51,43,35,  
              62,54,46,38,30,22,14,  
              6,61,53,45,37,29,21,  
              13,5,60,52,44,36,28,  
              20,12,4,27,19,11,3};  
  
//置換選擇2  
int PC_2[48] = {13,16,10,23, 0, 4,
                 2,27,14, 5,20, 9,
                22,18,11, 3,25, 7,
                15, 6,26,19,12, 1,
                40,51,30,36,46,54,
                29,39,50,44,32,47,
                43,48,38,55,33,52,
                45,41,49,35,28,31};  
  
//對左移次數的規定  
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


/* 第一個 C 程式  (hello.c) */
main() {
   printf("hello, This is 3-DES homework \n");
   
   FILE *fPtr;   /*宣告FILE資料型態的 指標*/ 
   FILE *fKey1;   /*宣告FILE資料型態的 指標*/ 
   FILE *fKey2;   /*宣告FILE資料型態的 指標*/ 
   FILE *fKey3;   /*宣告FILE資料型態的 指標*/    
   
   char fname[] = "plainText.txt" ;
   char fKeyName1[] = "key1.txt" ;
   char fKeyName2[] = "key2.txt" ;
   char fKeyName3[] = "key3.txt" ;
   
   
   
   printf("我會開啟原文:%s\n\n",fname);
   fPtr = fopen(fname,"r");  /* fopen function , 給予檔案名稱，和寫入方式 */
   
   printf("我會開啟KEY1:%s\n\n",fKeyName1);
   fKey1 = fopen(fKeyName1,"r");  /* fopen function , 給予檔案名稱，和寫入方式 */
   
   printf("我會開啟KEY2:%s\n\n",fKeyName2);
   fKey2 = fopen(fKeyName2,"r");  /* fopen function , 給予檔案名稱，和寫入方式 */
   
   printf("我會開啟KEY3:%s\n\n",fKeyName3);
   fKey3 = fopen(fKeyName3,"r");  /* fopen function , 給予檔案名稱，和寫入方式 */
   
   char8 block ;
   char8 key1 ;
   char8 key2 ;
   char8 key3 ;
   
   GetPlainText( block, fPtr ) ;
   GetKEY( key1, fKey1 ) ;
   GetKEY( key2, fKey2 ) ;
   GetKEY( key3, fKey3 ) ;
 

  //fprintf(fPtr, " 要寫入的字串 ");   /* 將字串寫入檔案 */

   fclose(fPtr); /* 關閉檔案 */ 
   fclose(fKey1); /* 關閉檔案 */ 
   fclose(fKey2); /* 關閉檔案 */ 
   fclose(fKey3); /* 關閉檔案 */ 
   
   
  
   
   
   char64 block64 ;
   char64 key64_1 ;
   char64 key64_2 ;
   char64 key64_3 ;
   
   
   char8  chiperText8 ;
   
   
   printf(  "原文轉BLOCK64:\n" );
   
   /* 用0x01弱金鑰 對12345678加密 的結果 
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
   
   
   printf(  "密鑰1轉BLOCK64:\n" );
   
   //  這是弱金鑰的測試 
   // for ( int i=0 ; i < 8 ; i++ ) key1[i] = 0x01;
   
   
   Extend8To64( key64_1,key1 ) ;
   
   
   subkeySet subkeySet1 ;
   
   GenerateSubKeySet(subkeySet1 , key64_1 ) ;
   
   //////////////////////////////////////////////////////////////////////
   
   printf(  "密鑰2轉BLOCK64:\n" );
   
   //  這是弱金鑰的測試 
   for ( int i=0 ; i < 8 ; i++ ) key2[i] = 0x01;
   
   
   Extend8To64( key64_2,key2 ) ;
   
   
   subkeySet subkeySet2 ;
   
   GenerateSubKeySet(subkeySet2 , key64_2 ) ;
   
   ////////////////////////////////////////////////////////////
   
   printf(  "密鑰3轉BLOCK64:\n" );
   
   // 這是弱金鑰的測試 
   for ( int i=0 ; i < 8 ; i++ ) key3[i] = 0x01;
   
   
   Extend8To64( key64_3,key3 ) ;
   
   
   subkeySet subkeySet3 ;
   
   GenerateSubKeySet(subkeySet3 , key64_3 ) ;
   
   
   
   
   DES( block64,subkeySet1 ) ;
   //DESDecoding( block64,subkeySet2 ) ;
   //DES( block64,subkeySet3 ) ;
   
   
   // block64 會變成密文 
   DeExtend64To8( block64,chiperText8 ) ;
   
   
   
   
   
   
   
 
 
   system("pause");
   
   return( 0 );
}


void GetPlainText( char8 charArray, FILE *fp ) {
     for ( int i = 0 ; i <=7  ; i ++ ) {
       charArray[i] = 0x00 ;
     } // for
     
     for ( int i = 0 ; i < 8 ; i++ ) fscanf(fp,"%c", &charArray[i] );
     
     printf(  "原文是這個:\n\"" );
     
     
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
     
     printf(  "KEY是這個:\n\"" );
     
     
     for ( int i = 0 ; i <=7  ; i ++ ) {
       printf(  "%c",charArray[i] );
     } // for
	 
     printf(  "\"\n" );
     
}  // void GetChar( char charArray[], FILE fileName ) { end


void Extend8To64( char64 block64,char8 block8) {
     
     
     
     
     for ( int base = 0 ; base < 8 ; base ++ ) {
       
       for ( int i = 0 ; i < 8 ; i ++ ) {
           
           block64[base*8+i]=((( block8[base]<< i )& 0x80 )>>7);
           
           // 不要問 不要說 一切盡在不言中 這是位元的邏輯運算 
           
       } // for 
       
       
     } // for
     
     
     
     
     printf(  "↓↓==block64長這樣==↓↓\n" );
     
     for ( int i =0  ; i <= 63   ; i ++ ) {
       if ( block64[i] == 0x00 ) printf( "0" );
       else if ( block64[i] == 0x01 ) printf( "1" );
       else printf( "\n%d:is a error\n",i );
       
       if ( (i+1)%4 == 0 ) printf(  " " );
       if ( (i+1)%8 == 0 ) printf(  "\n" );
     } // for
     
     printf(  "↑↑==block64長這樣==↑↑\n" );
     
     
     
     
     
     
     
} // void 




void DeExtend64To8( char64 block64,char8 block8 ) {
     printf(  "↓↓==block64密文長這樣==↓↓\n" );
     
     for ( int i =0  ; i <= 63   ; i ++ ) {
       if ( block64[i] == 0x00 ) printf( "0" );
       else if ( block64[i] == 0x01 ) printf( "1" );
       else printf( "\n%d:is a error\n",i );
       
       if ( (i+1)%4 == 0 ) printf(  " " );
       if ( (i+1)%8 == 0 ) printf(  "\n" );
     } // for
     
     printf(  "↑↑==block64密文長這樣==↑↑\n" );
     
     
     
     for ( int base = 0 ; base < 8 ; base ++ ) {
         
         block8[base] = 0x00;
         
       
       
       for ( int i = 0 ; i < 8 ; i ++ ) {
           
           block8[base] = ( ( block64[8*base+i] << (7-i) ) ^ block8[base] ); 
           
           // 不要問 不要說 一切盡在不言中 這是位元的邏輯運算 
           
       } // for 
       
       
     } // for
     
     
     
     
     printf(  "↓↓==block64密文的16進位表示法長這樣==↓↓\n" );
     for ( int i = 0 ; i < 8 ; i++ ) {
         printf(  "0x%x\n", block8[i] );
     } // for
     printf(  "↑↑==block64密文的16進位表示法長這樣==↑↑\n" );
     
     
     
     printf(  "如果你堅持的話 我可以給你看字串長這樣:\n" );
     for ( int i = 0 ; i < 8 ; i++ ) {
         printf(  "%c", block8[i] );
     } // for
     
     printf(  "\nMaybe換成直線排列比較好看吧?:\n" );
      for ( int i = 0 ; i < 8 ; i++ ) {
         printf(  "%c\n", block8[i] );
     } // for
     
     printf(  "\n" );
     
     
}  // void DeExtend64To8( char64 block64,char8 block8 ) ;


void DES( char64 block,subkeySet keySet ) {
          
          /*
          for ( int j = 0 ; j < 16 ; j++ ) {
              printf(  "↓↓==第%d把KEY長這樣==↓↓\n" , j);
              for ( int i = 0 ; i < 48 ; i++ ) {
                  if ( keySet[j][i] == 0x00 ) printf( "0" );
                  else if ( keySet[j][i] == 0x01 ) printf( "1" );
                  else printf( "\n(%d,%d):is a error\n",j,i );
                  
                  if ( (i+1)%4 == 0 ) printf(  " " );
                  if ( (i+1)%8 == 0 ) printf(  "\n" );
              } // for
              printf(  "↑↑==第%d把KEY長這樣==↑↑\n" ,j );
          } // for 
          */
          
          
          DES_IP_Transform(block);  // 先進行 IP 置換 
          
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
     
     
     //加密跟解密基本上是作一樣的事
     //不過解密KEY是從第16把開始做到第1把 
    
    char48 copyRight;  
    
  
    DES_IP_Transform(block);  // 先進行 IP 置換 
      
    
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
     
     for( int i = 0; i < 16; i++){ //循環16次 生出16把SUBKEY 
        DES_ROL(temp,MOVE_TIMES[i]);//根據循環表 循環左移  
        DES_PC2_Transform(temp,subkeySet1[i]);//PC2置換  
    }  
    
    return ;  
     
             
} // void GenerateSubKeySet( subkeySet subkeySet1 ,char64 key ) {








//密鑰置換1  
void DES_PC1_Transform(char64 key, char56 temp) {  
    int i;      
    for(i = 0; i < 56; i++){  
        temp[i] = key[PC_1[i]];  
    }  
    return;  
}  


//密鑰置換2
void DES_PC2_Transform(char56 key, char48 temp ){  
    int i;  
    for(i = 0; i < 48; i++){  
        temp[i] = key[PC_2[i]];  
    }  
    return ;  
} 


//循環左移  
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




//IP置換 
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

//IP逆置換 IP^-1 
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
  
//擴展置換  
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
  
//P置換 
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
  
//S盒置換 
void DES_SBOX(char48 data){  
    int cnt;  
    int line,row,output;  
    int cur1,cur2;  
    for(cnt = 0; cnt < 8; cnt++){  
        cur1 = cnt*6;  
        cur2 = cnt<<2;  
          
        //?算在S盒中的行与列  
        line = (data[cur1]<<1) + data[cur1+5];  
        row = (data[cur1+1]<<3) + (data[cur1+2]<<2)  
            + (data[cur1+3]<<1) + data[cur1+4];  
        output = S[cnt][line][row];  
  
        //化?2?制  
        data[cur2] = (output&0X08)>>3;  
        data[cur2+1] = (output&0X04)>>2;  
        data[cur2+2] = (output&0X02)>>1;  
        data[cur2+3] = output&0x01;  
    }     
    return ;  
}  


//交換 
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




