/*
 * Last changed at upstream commit 72599d583c232ea78d6461b5b502426c6e5a1ec9
 * https://github.com/espressif/esp32c3-bt-lib/commit/72599d583c232ea78d6461b5b502426c6e5a1ec9
 * Upstream date: 2025-05-19 16:27:45 +0800
 * Upstream subject: Update bt lib for ESP32-C3 and ESP32-S3(6cfabcd8)
 * Source: libbtdm_app -> sch_prog.o -> r_sch_prog_end_isr_hack
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_sch_prog_end_isr_hack(undefined4 param_1)

{
  (**(code **)(_r_ip_funcs_p + 0x8fc))(*(code **)(_r_ip_funcs_p + 0x8fc));
  (**(code **)(_r_ip_funcs_p + 0x904))(param_1,*(code **)(_r_ip_funcs_p + 0x904));
                    /* WARNING: Could not recover jumptable at 0x00010376. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_ip_funcs_p + 0x900))(*(code **)(_r_ip_funcs_p + 0x900));
  return;
}

