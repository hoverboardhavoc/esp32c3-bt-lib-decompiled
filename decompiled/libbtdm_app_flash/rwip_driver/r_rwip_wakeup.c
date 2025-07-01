/*
 * Last changed at upstream commit 0c68809d62e432427de97b5294f6619307f62f40
 * https://github.com/espressif/esp32c3-bt-lib/commit/0c68809d62e432427de97b5294f6619307f62f40
 * Upstream date: 2025-07-01 15:07:54 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(2edb0b0)
 * Source: libbtdm_app_flash -> rwip_driver.o -> r_rwip_wakeup
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_rwip_wakeup(void)

{
  undefined4 uVar1;
  uint uVar2;
  
  uVar1 = _DAT_60042008;
  if (*(code **)(_r_osi_funcs_p + 0xa0) != (code *)0x0) {
    (**(code **)(_r_osi_funcs_p + 0xa0))();
  }
  _btdm_pwr_state = 3;
  r_rwip_prevent_sleep_clear_hack(0x10);
  r_rwip_prevent_sleep_set_hack(1);
  _DAT_60042000 = _DAT_60042000 & 0x7fffffff;
  uVar2 = r_rwip_lpcycles_2_hus(uVar1,&rwip_env);
  _DAT_60031044 = uVar2 / 0x271 | 0x80000000;
  uVar2 = ((uVar2 / 0x271) * 0x271 - uVar2) + 0x270;
  if ((uVar2 & 0xfc00) != 0) {
    r_assert_err(0,"rwip_driver.c",0x45c);
  }
  _DAT_60031040 = uVar2 & 0xffff;
  _DAT_60042000 = _DAT_60042000 | 8;
  _DAT_60031018 = 0xffffffff;
  if (sdk_cfg_priv_opts != '\0') {
    for (; (_DAT_600312d8 >> 5 & 0x1f) != 0; _DAT_600312d8 = _DAT_600312d8 | 1) {
    }
  }
  _DAT_6003100c = 9;
  return;
}

