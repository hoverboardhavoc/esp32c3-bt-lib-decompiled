/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
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
  (**(code **)(_r_modules_funcs_p + 0x268))(rwip_rst_state,*(code **)(_r_modules_funcs_p + 0x268));
  (**(code **)(_r_modules_funcs_p + 0x130))(*(code **)(_r_modules_funcs_p + 0x130));
  iVar1 = (**(code **)(_r_plf_funcs_p + 0xf0))(*(code **)(_r_plf_funcs_p + 0xf0));
  if (*(char *)(iVar1 + 0x20) != '\0') {
    (**(code **)(_r_modules_funcs_p + 0x378))(rwip_rst_state,*(code **)(_r_modules_funcs_p + 0x378))
    ;
  }
  (**(code **)(_r_ip_funcs_p + 0x73c))(rwip_rst_state,*(code **)(_r_ip_funcs_p + 0x73c));
  (**(code **)(_r_ip_funcs_p + 0x84))(rwip_rst_state,*(code **)(_r_ip_funcs_p + 0x84));
  if (*(code **)(_r_hli_funcs_p + 8) != (code *)0x0) {
    (**(code **)(_r_hli_funcs_p + 8))(rwip_rst_state);
  }
  (**(code **)(_r_ip_funcs_p + 0x128))(rwip_rst_state,*(code **)(_r_ip_funcs_p + 0x128));
  bb_int_init(rwip_rst_state);
  (**(code **)(_r_modules_funcs_p + 0x330))(rwip_rst_state,*(code **)(_r_modules_funcs_p + 0x330));
  (**(code **)(_r_ip_funcs_p + 0x6ac))(rwip_rst_state,*(code **)(_r_ip_funcs_p + 0x6ac));
  (**(code **)(_r_ip_funcs_p + 0x6c4))(rwip_rst_state,*(code **)(_r_ip_funcs_p + 0x6c4));
  (**(code **)(_r_ip_funcs_p + 0x6e0))(rwip_rst_state,*(code **)(_r_ip_funcs_p + 0x6e0));
  (**(code **)(_r_ip_funcs_p + 0x704))(rwip_rst_state,*(code **)(_r_ip_funcs_p + 0x704));
  (**(code **)(_r_ip_funcs_p + 0x728))(rwip_rst_state,*(code **)(_r_ip_funcs_p + 0x728));
  (**(code **)(_r_modules_funcs_p + 0x29c))(rwip_rst_state,*(code **)(_r_modules_funcs_p + 0x29c));
  (**(code **)(_r_modules_funcs_p + 0x288))(1,*(code **)(_r_modules_funcs_p + 0x288));
  if (rwip_rst_state == '\x02') {
    (*_rwip_rf)(_rwip_rf);
  }
  rwip_rst_state = 2;
  (**(code **)(_r_osi_funcs_p + 0x18))(*(code **)(_r_osi_funcs_p + 0x18));
  _btdm_pwr_state = 0;
                    /* WARNING: Could not recover jumptable at 0x0001033a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_osi_funcs_p + 0x38))(g_waking_sleeping_sem,*(code **)(_r_osi_funcs_p + 0x38));
  return;
}

