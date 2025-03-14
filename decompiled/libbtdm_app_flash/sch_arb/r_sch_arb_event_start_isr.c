/*
 * Last changed at upstream commit e668c2d101ee46ee1950819607694fb852aecae0
 * https://github.com/espressif/esp32c3-bt-lib/commit/e668c2d101ee46ee1950819607694fb852aecae0
 * Upstream date: 2025-03-14 11:07:43 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(6e312587)
 * Source: libbtdm_app_flash -> sch_arb.o -> r_sch_arb_event_start_isr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_sch_arb_event_start_isr(void)

{
  uint uVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  int extraout_a1;
  uint uVar5;
  uint extraout_a1_00;
  int iVar6;
  
  iVar4 = _sch_arb_env;
  uVar2 = r_rwip_time_get();
  while (iVar4 != 0) {
    iVar6 = *(int *)(iVar4 + 4) - (uint)rwip_prog_delay;
    if ((((1 - uVar2) + iVar6 & 0xfffffff) < 0x7ffffff) &&
       (((iVar6 + 1U & 0xfffffff) != uVar2 || (extraout_a1_00 <= *(uint *)(iVar4 + 8))))) {
      goto _L60;
    }
    uVar3 = r_co_list_pop_front(&sch_arb_env);
    r_co_list_push_back(&sch_arb_env,uVar3);
    iVar4 = _sch_arb_env;
  }
  goto _L57;
  while( true ) {
    _r_co_list_extract_after = r_co_list_pop_front(&sch_arb_env);
    if (*(code **)(_r_co_list_extract_after + 0x18) != (code *)0x0) {
      (**(code **)(_r_co_list_extract_after + 0x18))();
    }
    iVar4 = ble_evt_kick_delay_get();
    if (iVar4 != 0) {
      ble_evt_kick_delay_update(0);
      r_sch_prog_skip_isr(0xff);
    }
    iVar4 = _sch_arb_env;
    if (_sch_arb_env == 0) break;
_L60:
    iVar6 = *(int *)(iVar4 + 4) - (uint)rwip_prog_delay;
    if (((~uVar2 + iVar6 & 0xfffffff) < 0x7ffffff) &&
       (((iVar6 - 1U & 0xfffffff) != uVar2 || (extraout_a1_00 < *(uint *)(iVar4 + 8))))) break;
  }
_L57:
  if (_r_co_list_insert_after != 0) {
    r_rwip_sw_int_req();
  }
  uVar2 = r_rwip_time_get();
  uVar5 = extraout_a1 + 400;
  if (0x270 < uVar5) {
    uVar5 = extraout_a1 - 0xe1;
    uVar2 = uVar2 + 1 & 0xfffffff;
  }
  if (_sch_arb_env == 0) {
    uVar5 = 0;
    uVar2 = 0xffffffff;
  }
  else {
    uVar1 = *(int *)(_sch_arb_env + 4) - (uint)rwip_prog_delay & 0xfffffff;
    if (((uVar1 - uVar2 & 0xfffffff) < 0x7ffffff) &&
       ((uVar1 != uVar2 || (uVar2 = uVar1, uVar5 < *(uint *)(_sch_arb_env + 8))))) {
      uVar2 = uVar1;
      uVar5 = *(uint *)(_sch_arb_env + 8);
    }
  }
  r_rwip_timer_hus_set(uVar2,uVar5);
  return;
}

