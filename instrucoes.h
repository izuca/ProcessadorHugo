//Declarando instruções a serem utilizadas

void hlt();

void nop(unsigned short int pc, unsigned char lr);

void add(unsigned short int a, unsigned short int b);
void sub(unsigned short int a, unsigned short int b);
void mul(unsigned short int a, unsigned short int b);
void div(unsigned short int a, unsigned short int b);

void cmp(unsigned short int a, unsigned short int b, unsigned char e, unsigned char l, unsigned char g );
void xchg(unsigned short int a, unsigned short int b, unsigned short int t);

void land(unsigned short int a, unsigned short int b);
void lor(unsigned short int a, unsigned short int b);
void lxor(unsigned short int a, unsigned short int b);
void lnor(unsigned short int a);

//Mudar int endereco pra unsigned short int
void je(int endereco, unsigned short int pc, unsigned char e);
void jne(int endereco, unsigned short int pc, unsigned char e);
void jl(int endereco, unsigned char l, unsigned short int pc);
void jle(int endereco, unsigned char l, unsigned char e, unsigned short int pc);
void jg(int endereco, unsigned char g, unsigned short int pc);
void jge(int endereco, unsigned char g, unsigned char e, unsigned short int pc);
void jmp(int endereco, unsigned short int pc);

void lda(unsigned short int mar, unsigned short int a, unsigned char memoria[]);
void ldb(unsigned short int mar, unsigned short int b, unsigned char memoria[]);
void ldrb(unsigned short int mar, unsigned short int a, unsigned short int b, unsigned char memoria[]);

void sta(unsigned short int mar, unsigned char memoria[], unsigned short int a);
void stb(unsigned short int mar, unsigned char memoria[], unsigned short int b);

void movial(unsigned short int a, unsigned short int imm);
void moviah(unsigned short int a, unsigned short int imm);

void addia(unsigned short int a, unsigned short int imm);
void subia(unsigned short int a, unsigned short int imm);
void mulia(unsigned short int a, unsigned short int imm);
void divia(unsigned short int a, unsigned short int imm);

void lsh(unsigned short int a, unsigned short int imm);
void rsh(unsigned short int a, unsigned short int imm);

