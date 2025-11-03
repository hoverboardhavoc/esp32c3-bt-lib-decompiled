/*
 * Last changed at upstream commit 099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * https://github.com/espressif/esp32c3-bt-lib/commit/099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * Upstream date: 2025-11-03 14:51:49 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(0871069)
 * Source: libbtdm_app_flash -> sch_arb.o -> r_sch_arb_sw_isr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_sch_arb_sw_isr(void)

{
  char cVar1;
  int iVar2;
  
  cVar1 = r_co_list_size(&sch_arb_env);
  while( true ) {
    if (cVar1 < '\x01') break;
    iVar2 = r_co_list_pop_front(&sch_arb_env);
    if (iVar2 == 0) {
      r_assert_err("sch_arb.c",0x3d3);
    }
    if (*(code **)(iVar2 + 0x20) != (code *)0x0) {
      (**(code **)(iVar2 + 0x20))(iVar2);
    }
    cVar1 = cVar1 + -1;
  }
  return;
}

