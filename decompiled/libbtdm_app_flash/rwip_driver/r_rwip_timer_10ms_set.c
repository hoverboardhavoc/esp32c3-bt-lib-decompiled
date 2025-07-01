/*
 * Last changed at upstream commit 0c68809d62e432427de97b5294f6619307f62f40
 * https://github.com/espressif/esp32c3-bt-lib/commit/0c68809d62e432427de97b5294f6619307f62f40
 * Upstream date: 2025-07-01 15:07:54 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(2edb0b0)
 * Source: libbtdm_app_flash -> rwip_driver.o -> r_rwip_timer_10ms_set
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_rwip_timer_10ms_set(uint param_1)

{
  (**(code **)(_r_osi_funcs_p + 0x14))(*(code **)(_r_osi_funcs_p + 0x14));
  if (param_1 == 0xffffffff) {
    _DAT_6003100c = _DAT_6003100c & 0xfffffdff;
    _r_sch_alarm_timer_isr = -1;
    if (DAT_00012061 != '\0') {
      _DAT_6003138c = 0x200;
    }
  }
  else {
    _r_sch_alarm_timer_isr = param_1 << 5;
    if ((param_1 & 0xff800000) != 0) {
      r_assert_err(0,"rwip_driver.c",0xc07);
    }
    _DAT_60031018 = 0x200;
    if (DAT_00012061 != '\0') {
      _DAT_6003138c = 0x200;
    }
    _DAT_6003100c = _DAT_6003100c | 0x200;
    _DAT_600310e4 = param_1;
  }
                    /* WARNING: Could not recover jumptable at 0x00010d72. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_osi_funcs_p + 0x18))(*(code **)(_r_osi_funcs_p + 0x18));
  return;
}

