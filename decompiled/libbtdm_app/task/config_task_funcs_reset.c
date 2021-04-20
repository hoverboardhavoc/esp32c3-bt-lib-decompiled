/*
 * Last changed at upstream commit 352d001fc7f5d34243047454b3f9e684577ce3e0
 * https://github.com/espressif/esp32c3-bt-lib/commit/352d001fc7f5d34243047454b3f9e684577ce3e0
 * Upstream date: 2021-04-20 15:58:00 +0800
 * Upstream subject: ESP32C3, ESP32S3: update libbtdm_app.a(47235b66)
 * Source: libbtdm_app -> task.o -> config_task_funcs_reset
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void config_task_funcs_reset(void)

{
  int iVar1;
  
  iVar1 = _r_plf_funcs_p;
  *(code **)(_r_plf_funcs_p + 0x28) = r_btdm_task_post_hack;
  *(code **)(iVar1 + 0x2c) = r_btdm_task_post_from_isr_hack;
  *(code **)(iVar1 + 0x30) = r_btdm_task_recycle_hack;
  return;
}

