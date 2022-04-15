/* 
 *  Beep functions and CW
 */

#define DIT_DURATION 50

void beep(int on, int off) {
  freq = WSPR_FREQ;
  digitalWrite(2, HIGH);
  digitalWrite(4, HIGH);
  digitalWrite(5, HIGH);
  digitalWrite(6, HIGH);
  digitalWrite(7, HIGH);
  si5351.init(SI5351_CRYSTAL_LOAD_0PF, TCXO_REF_FREQ, 0);
  si5351.update_status();
  delay(off);
  si5351.set_freq(freq * 100, SI5351_CLK0);
  delay(on);
  si5351.output_enable(SI5351_CLK0, 0);
  digitalWrite(2, LOW);  // Si5351 off
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
  digitalWrite(7, LOW);
  sodaq_wdt_reset();
}

void dit() { beep(DIT_DURATION, DIT_DURATION); }

void dah() { beep(DIT_DURATION * 3, DIT_DURATION); }

void sk() { delay(DIT_DURATION * 3 ); }

void cw_a() {  dit(); dah();                sk(); }
void cw_b() {  dah(); dit(); dit(); dit();  sk(); }
void cw_c() {  dah(); dit(); dah(); dit();  sk(); }
void cw_d() {  dah(); dit(); dit();         sk(); }
void cw_e() {  dit();                       sk(); }
void cw_f() {  dit(); dit(); dah(); dit();  sk(); }
void cw_g() {  dah(); dah(); dit();         sk(); }
void cw_h() {  dit(); dit(); dit(); dit();  sk(); }
void cw_i() {  dit(); dit();                sk(); }
void cw_j() {  dit(); dah(); dah(); dah();  sk(); }
void cw_k() {  dah(); dit(); dah();         sk(); }
void cw_l() {  dit(); dah(); dit(); dit();  sk(); }
void cw_m() {  dah(); dah();                sk(); }
void cw_n() {  dah(); dit();                sk(); }
void cw_o() {  dah(); dah(); dah();         sk(); }
void cw_p() {  dit(); dah(); dah(); dit();  sk(); }
void cw_q() {  dah(); dah(); dit(); dah();  sk(); }
void cw_r() {  dit(); dah(); dit();         sk(); }
void cw_s() {  dit(); dit(); dit();         sk(); }
void cw_t() {  dah();                       sk(); }
void cw_u() {  dit(); dit(); dah();         sk(); }
void cw_v() {  dit(); dit(); dit(); dah();  sk(); }
void cw_w() {  dit(); dah(); dah();         sk(); }
void cw_x() {  dah(); dit(); dit(); dah();  sk(); }
void cw_y() {  dah(); dit(); dah(); dah();  sk(); }
void cw_z() {  dah(); dah(); dit(); dit();  sk(); }

void cw_1() { dit(); dah(); dah(); dah(); dah(); sk(); }
void cw_2() { dit(); dit(); dah(); dah(); dah(); sk(); }
void cw_3() { dit(); dit(); dit(); dah(); dah(); sk(); }
void cw_4() { dit(); dit(); dit(); dit(); dah(); sk(); }
void cw_5() { dit(); dit(); dit(); dit(); dit(); sk(); }
void cw_6() { dah(); dit(); dit(); dit(); dit(); sk(); }
void cw_7() { dah(); dah(); dit(); dit(); dit(); sk(); }
void cw_8() { dah(); dah(); dah(); dit(); dit(); sk(); }
void cw_9() { dah(); dah(); dah(); dah(); dit(); sk(); }
void cw_0() { dah(); dah(); dah(); dah(); dah(); sk(); }

void cw(char call[]) {
  for(int i = 0; call[i] != '\0'; ++i) {
    switch (toLowerCase(call[i])) {
      case 'a': cw_a(); break; case 'b': cw_b(); break; case 'c': cw_c(); break;
      case 'd': cw_d(); break; case 'e': cw_e(); break; case 'f': cw_f(); break;
      case 'g': cw_g(); break; case 'h': cw_h(); break; case 'i': cw_i(); break;
      case 'j': cw_j(); break; case 'k': cw_k(); break; case 'l': cw_l(); break;
      case 'm': cw_m(); break; case 'n': cw_n(); break; case 'o': cw_o(); break;
      case 'p': cw_p(); break; case 'q': cw_q(); break; case 'r': cw_r(); break;
      case 's': cw_s(); break; case 't': cw_t(); break; case 'u': cw_u(); break;
      case 'v': cw_v(); break; case 'w': cw_w(); break; case 'x': cw_x(); break;
      case 'y': cw_y(); break; case 'z': cw_z(); break; case '1': cw_1(); break;
      case '2': cw_2(); break; case '3': cw_3(); break; case '4': cw_4(); break;
      case '5': cw_5(); break; case '6': cw_6(); break; case '7': cw_7(); break;
      case '8': cw_8(); break; case '9': cw_9(); break; case '0': cw_0(); break;
      default: break;
    }
  }
}
