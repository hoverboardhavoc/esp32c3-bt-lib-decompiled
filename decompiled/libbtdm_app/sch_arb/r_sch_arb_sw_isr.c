/*
 * Last changed at upstream commit 099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * https://github.com/espressif/esp32c3-bt-lib/commit/099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * Upstream date: 2025-11-03 14:51:49 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(0871069)
 * Source: libbtdm_app -> sch_arb.o -> r_sch_arb_sw_isr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_sch_arb_sw_isr(void)

{
  char cVar1;
  int iVar2;
  
  for (cVar1 = (**(code **)(_r_modules_funcs_p + 0x50))
                         (&sch_arb_env,*(code **)(_r_modules_funcs_p + 0x50)); '\0' < cVar1;
      cVar1 = cVar1 + -1) {
    iVar2 = (**(code **)(_r_modules_funcs_p + 0x40))
                      (&sch_arb_env,*(code **)(_r_modules_funcs_p + 0x40));
    if (iVar2 == 0) {
      (**(code **)(_r_plf_funcs_p + 8))("sch_arb.c",0x3d3,*(code **)(_r_plf_funcs_p + 8));
    }
    if (*(code **)(iVar2 + 0x20) != (code *)0x0) {
      (**(code **)(iVar2 + 0x20))(iVar2);
    }
  }
  return;
}

