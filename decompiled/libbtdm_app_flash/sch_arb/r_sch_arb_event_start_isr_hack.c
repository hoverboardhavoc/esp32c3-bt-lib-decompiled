/*
 * Last changed at upstream commit 099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * https://github.com/espressif/esp32c3-bt-lib/commit/099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * Upstream date: 2025-11-03 14:51:49 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(0871069)
 * Source: libbtdm_app_flash -> sch_arb.o -> r_sch_arb_event_start_isr_hack
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_sch_arb_event_start_isr_hack(void)

{
  bool bVar1;
  uint uVar2;
  uint uVar3;
  undefined4 uVar4;
  int iVar5;
  int extraout_a1;
  uint extraout_a1_00;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  
  iVar5 = _sch_arb_env;
  uVar3 = r_rwip_time_get();
  while (iVar5 != 0) {
    iVar9 = *(int *)(iVar5 + 4) - (uint)rwip_prog_delay;
    if ((((1 - uVar3) + iVar9 & 0xfffffff) < 0x7ffffff) &&
       (((iVar9 + 1U & 0xfffffff) != uVar3 || (extraout_a1_00 <= *(uint *)(iVar5 + 8))))) goto _L64;
    r_ble_log_internal_x3(0x4009019d,iVar5,*(undefined4 *)(iVar5 + 8));
    uVar4 = r_co_list_pop_front(&sch_arb_env);
    r_co_list_push_back(&sch_arb_env,uVar4);
    iVar5 = _sch_arb_env;
  }
  goto _L57;
  while( true ) {
    _r_co_list_extract_after = r_co_list_pop_front(&sch_arb_env);
    if (*(code **)(_r_co_list_extract_after + 0x18) != (code *)0x0) {
      (**(code **)(_r_co_list_extract_after + 0x18))();
    }
    iVar5 = ble_evt_kick_delay_get();
    if (iVar5 != 0) {
      ble_evt_kick_delay_update(0);
      r_sch_prog_skip_isr(0xff);
    }
    iVar5 = _sch_arb_env;
    if (_sch_arb_env == 0) break;
_L64:
    iVar9 = *(int *)(iVar5 + 4) - (uint)rwip_prog_delay;
    if ((((iVar9 - uVar3) - 1 & 0xfffffff) < 0x7ffffff) &&
       (((iVar9 - 1U & 0xfffffff) != uVar3 || (extraout_a1_00 < *(uint *)(iVar5 + 8))))) break;
  }
_L57:
  if (_r_co_list_insert_after != 0) {
    r_rwip_sw_int_req();
  }
  uVar3 = r_rwip_time_get();
  uVar8 = extraout_a1 + 400;
  if (0x270 < uVar8) {
    uVar8 = extraout_a1 - 0xe1;
    uVar3 = uVar3 + 1 & 0xfffffff;
  }
  if (_sch_arb_env == 0) {
    r_rwip_timer_hus_set(0xffffffff,0);
    uVar7 = 0;
    uVar3 = 0xffffffff;
  }
  else {
    uVar6 = *(uint *)(_sch_arb_env + 8);
    uVar2 = *(int *)(_sch_arb_env + 4) - (uint)rwip_prog_delay & 0xfffffff;
    uVar7 = uVar8;
    if ((((uVar2 - uVar3 & 0xfffffff) < 0x7ffffff) &&
        (bVar1 = uVar2 == uVar3, uVar3 = uVar2, uVar7 = uVar6, bVar1)) && (uVar6 < uVar8)) {
      uVar7 = uVar8;
    }
    r_rwip_timer_hus_set(uVar3,uVar7);
  }
  r_ble_log_internal_x2(0x2009019e,uVar3,uVar7);
  return;
}

