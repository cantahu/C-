#ifndef _BASE64_H_
#define _BASE64_H_

typedef struct {
	uint8_t *data;
	uint32_t datalen;
}base64_t;

const uint8_t base64_tbl[] ={
	'A','B','C','D','E','F','G','H','I','J',
	'K','L','M','N','O','P','Q','R','S','T',
	'U','V','W','X','Y','Z','a','b','c','d',
	'e','f','g','h','i','j','k','l','m','n',
	'o','p','q','r','s','t','u','v','w','x',
	'y','z','0','1','2','3','4','5','6','7',
	'8','9','+','/'
};

base64_t *creat_base64_ascii(int8_t* src, uint32_t len);
void free_base64(base64_t *obj);


#endif //_BASE64_H_
