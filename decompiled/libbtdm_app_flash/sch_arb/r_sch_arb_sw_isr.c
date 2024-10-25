/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
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
      r_assert_err("sch_arb.c",0x3cd);
    }
    if (*(code **)(iVar2 + 0x20) != (code *)0x0) {
      (**(code **)(iVar2 + 0x20))(iVar2);
    }
    cVar1 = cVar1 + -1;
  }
  return;
}

