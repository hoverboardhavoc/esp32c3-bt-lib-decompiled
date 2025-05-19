/*
 * Last changed at upstream commit 72599d583c232ea78d6461b5b502426c6e5a1ec9
 * https://github.com/espressif/esp32c3-bt-lib/commit/72599d583c232ea78d6461b5b502426c6e5a1ec9
 * Upstream date: 2025-05-19 16:27:45 +0800
 * Upstream subject: Update bt lib for ESP32-C3 and ESP32-S3(6cfabcd8)
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
  uint uVar4;
  uint uVar5;
  undefined4 uVar6;
  int iVar7;
  int extraout_a1;
  uint extraout_a1_00;
  uint uVar8;
  int iVar9;
  
  iVar7 = _sch_arb_env;
  uVar5 = r_rwip_time_get();
  while (iVar7 != 0) {
    iVar9 = *(int *)(iVar7 + 4) - (uint)rwip_prog_delay;
    if ((((1 - uVar5) + iVar9 & 0xfffffff) < 0x7ffffff) &&
       (((iVar9 + 1U & 0xfffffff) != uVar5 || (extraout_a1_00 <= *(uint *)(iVar7 + 8))))) goto _L70;
    iVar9 = r_sdk_config_get_opts_ext();
    if (((*(uint *)(iVar9 + 0x28) & 1) != 0) &&
       (iVar9 = r_sdk_config_get_opts_ext(), *(byte *)(iVar9 + 0x2c) < 3)) {
      r_ble_log_internal_x3(0x40040004,iVar7,*(undefined4 *)(iVar7 + 4),*(undefined4 *)(iVar7 + 8));
    }
    uVar6 = r_co_list_pop_front(&sch_arb_env);
    r_co_list_push_back(&sch_arb_env,uVar6);
    iVar7 = _sch_arb_env;
  }
  goto _L63;
  while( true ) {
    _r_co_list_extract_after = r_co_list_pop_front(&sch_arb_env);
    if (*(code **)(_r_co_list_extract_after + 0x18) != (code *)0x0) {
      (**(code **)(_r_co_list_extract_after + 0x18))();
    }
    iVar7 = ble_evt_kick_delay_get();
    if (iVar7 != 0) {
      ble_evt_kick_delay_update(0);
      r_sch_prog_skip_isr(0xff);
    }
    iVar7 = _sch_arb_env;
    if (_sch_arb_env == 0) break;
_L70:
    iVar9 = *(int *)(iVar7 + 4) - (uint)rwip_prog_delay;
    if ((((iVar9 - uVar5) - 1 & 0xfffffff) < 0x7ffffff) &&
       (((iVar9 - 1U & 0xfffffff) != uVar5 || (extraout_a1_00 < *(uint *)(iVar7 + 8))))) break;
  }
_L63:
  if (_r_co_list_insert_after != 0) {
    r_rwip_sw_int_req();
  }
  uVar5 = r_rwip_time_get();
  uVar8 = extraout_a1 + 400;
  if (0x270 < uVar8) {
    uVar8 = extraout_a1 - 0xe1;
    uVar5 = uVar5 + 1 & 0xfffffff;
  }
  if (_sch_arb_env == 0) {
    r_rwip_timer_hus_set(0xffffffff,0);
    uVar4 = 0;
    uVar5 = 0xffffffff;
  }
  else {
    uVar3 = *(uint *)(_sch_arb_env + 8);
    uVar2 = *(int *)(_sch_arb_env + 4) - (uint)rwip_prog_delay & 0xfffffff;
    uVar4 = uVar8;
    if ((((uVar2 - uVar5 & 0xfffffff) < 0x7ffffff) &&
        (bVar1 = uVar2 == uVar5, uVar5 = uVar2, uVar4 = uVar3, bVar1)) && (uVar3 < uVar8)) {
      uVar4 = uVar8;
    }
    r_rwip_timer_hus_set(uVar5,uVar4);
  }
  iVar7 = r_sdk_config_get_opts_ext();
  if (((*(uint *)(iVar7 + 0x28) & 1) != 0) &&
     (iVar7 = r_sdk_config_get_opts_ext(), *(byte *)(iVar7 + 0x2c) < 2)) {
    r_ble_log_internal_x2(0x20040003,uVar5,uVar4);
    return;
  }
  return;
}

