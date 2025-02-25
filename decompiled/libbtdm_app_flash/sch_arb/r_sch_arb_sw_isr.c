/*
 * Last changed at upstream commit 2ce747aec8008d008fe34fa375a2aea3e7e48e9a
 * https://github.com/espressif/esp32c3-bt-lib/commit/2ce747aec8008d008fe34fa375a2aea3e7e48e9a
 * Upstream date: 2025-02-25 15:16:47 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(723439d)
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
      r_assert_err("sch_arb.c",0x3d1);
    }
    if (*(code **)(iVar2 + 0x20) != (code *)0x0) {
      (**(code **)(iVar2 + 0x20))(iVar2);
    }
    cVar1 = cVar1 + -1;
  }
  return;
}

