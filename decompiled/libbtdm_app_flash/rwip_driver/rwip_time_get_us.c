/*
 * Last changed at upstream commit 099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * https://github.com/espressif/esp32c3-bt-lib/commit/099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * Upstream date: 2025-11-03 14:51:49 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(0871069)
 * Source: libbtdm_app_flash -> rwip_driver.o -> rwip_time_get_us
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint rwip_time_get_us(void)

{
  uint uVar1;
  
  if ((_btdm_pwr_state & 0xfffffffb) == 0) {
    _DAT_6003101c = _DAT_6003101c | 0x80000000;
    do {
    } while ((int)_DAT_6003101c < 0);
    (**(code **)(_r_osi_funcs_p + 0x14))();
    uVar1 = _DAT_6003101c;
    (**(code **)(_r_osi_funcs_p + 0x18))(*(code **)(_r_osi_funcs_p + 0x18));
  }
  else {
    (**(code **)(_r_osi_funcs_p + 0x14))();
    uVar1 = _DAT_6003101c;
    r_rwip_lpcycles_2_hus(_DAT_60042008,&rwip_env);
    (**(code **)(_r_osi_funcs_p + 0x18))(*(code **)(_r_osi_funcs_p + 0x18));
  }
  return uVar1 & 0xfffffff;
}

