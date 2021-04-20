/*
 * Last changed at upstream commit 352d001fc7f5d34243047454b3f9e684577ce3e0
 * https://github.com/espressif/esp32c3-bt-lib/commit/352d001fc7f5d34243047454b3f9e684577ce3e0
 * Upstream date: 2021-04-20 15:58:00 +0800
 * Upstream subject: ESP32C3, ESP32S3: update libbtdm_app.a(47235b66)
 * Source: libbtdm_app -> rwip.o -> r_rwip_reset
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_rwip_reset(void)

{
  int iVar1;
  
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
  iVar1 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38));
  if ((*(char *)(iVar1 + 0x11) != '\0') || (sdk_cfg_priv_opts != '\0')) {
    (**(code **)(_r_ip_funcs_p + 0x120))(_LANCHOR0,*(code **)(_r_ip_funcs_p + 0x120));
  }
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
                    /* WARNING: Could not recover jumptable at 0x00010372. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_osi_funcs_p + 0x38))(g_waking_sleeping_sem);
  return;
}

