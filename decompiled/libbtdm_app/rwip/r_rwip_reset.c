/*
 * Last changed at upstream commit b223604efd557d0a5314afb3b751229df424d244
 * https://github.com/espressif/esp32c3-bt-lib/commit/b223604efd557d0a5314afb3b751229df424d244
 * Upstream date: 2021-06-24 21:26:02 +0800
 * Upstream subject: Update ESP32-C3 and ESP32-S3 bt lib (9c99115)
 * Source: libbtdm_app -> rwip.o -> r_rwip_reset
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_rwip_reset(void)

{
  (**(code **)(_r_osi_funcs_p + 0x14))(*(code **)(_r_osi_funcs_p + 0x14));
  (**(code **)(_r_modules_funcs_p + 0x268))(_LANCHOR0,*(code **)(_r_modules_funcs_p + 0x268));
  (**(code **)(_r_modules_funcs_p + 0x130))(*(code **)(_r_modules_funcs_p + 0x130));
  (**(code **)(_r_modules_funcs_p + 0x378))(_LANCHOR0,*(code **)(_r_modules_funcs_p + 0x378));
  (**(code **)(_r_ip_funcs_p + 0x73c))(_LANCHOR0,*(code **)(_r_ip_funcs_p + 0x73c));
  (**(code **)(_r_ip_funcs_p + 0x84))(_LANCHOR0,*(code **)(_r_ip_funcs_p + 0x84));
  if (*(code **)(_r_hli_funcs_p + 8) != (code *)0x0) {
    (**(code **)(_r_hli_funcs_p + 8))(_LANCHOR0);
  }
  (**(code **)(_r_ip_funcs_p + 0x128))(_LANCHOR0,*(code **)(_r_ip_funcs_p + 0x128));
  bb_int_init(_LANCHOR0);
  (**(code **)(_r_modules_funcs_p + 0x330))(_LANCHOR0,*(code **)(_r_modules_funcs_p + 0x330));
  (**(code **)(_r_ip_funcs_p + 0x6ac))(_LANCHOR0,*(code **)(_r_ip_funcs_p + 0x6ac));
  (**(code **)(_r_ip_funcs_p + 0x6c4))(_LANCHOR0,*(code **)(_r_ip_funcs_p + 0x6c4));
  (**(code **)(_r_ip_funcs_p + 0x6e0))(_LANCHOR0,*(code **)(_r_ip_funcs_p + 0x6e0));
  (**(code **)(_r_ip_funcs_p + 0x704))(_LANCHOR0,*(code **)(_r_ip_funcs_p + 0x704));
  (**(code **)(_r_ip_funcs_p + 0x728))(_LANCHOR0,*(code **)(_r_ip_funcs_p + 0x728));
  (**(code **)(_r_modules_funcs_p + 0x29c))(_LANCHOR0,*(code **)(_r_modules_funcs_p + 0x29c));
  (**(code **)(_r_modules_funcs_p + 0x288))(1,*(code **)(_r_modules_funcs_p + 0x288));
  if (_LANCHOR0 == '\x02') {
    (*_rwip_rf)(_rwip_rf);
  }
  _LANCHOR0 = 2;
  (**(code **)(_r_osi_funcs_p + 0x18))(*(code **)(_r_osi_funcs_p + 0x18));
  _btdm_pwr_state = 0;
                    /* WARNING: Could not recover jumptable at 0x0001032e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_osi_funcs_p + 0x38))(g_waking_sleeping_sem);
  return;
}

