/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> sch_arb.o -> r_sch_arb_event_start_isr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_sch_arb_event_start_isr(void)

{
  bool bVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  undefined4 uVar6;
  int extraout_a1;
  uint extraout_a1_00;
  uint uVar7;
  int iVar8;
  
  iVar4 = _sch_arb_env;
  uVar5 = r_rwip_time_get();
  while ((iVar4 != 0 &&
         ((iVar8 = *(int *)(iVar4 + 4) - (uint)rwip_prog_delay,
          0x7fffffe < ((1 - uVar5) + iVar8 & 0xfffffff) ||
          (((iVar8 + 1U & 0xfffffff) == uVar5 && (*(uint *)(iVar4 + 8) < extraout_a1_00))))))) {
    iVar8 = r_sdk_config_get_opts_ext();
    if (((*(uint *)(iVar8 + 0x28) & 1) != 0) &&
       (iVar8 = r_sdk_config_get_opts_ext(), *(byte *)(iVar8 + 0x2c) < 3)) {
      r_ble_log_internal_x3(0x40040004,iVar4,*(undefined4 *)(iVar4 + 4),*(undefined4 *)(iVar4 + 8));
    }
    uVar6 = r_co_list_pop_front(&sch_arb_env);
    r_co_list_push_back(&sch_arb_env,uVar6);
    iVar4 = _sch_arb_env;
  }
  while ((iVar4 != 0 &&
         ((iVar8 = *(int *)(iVar4 + 4) - (uint)rwip_prog_delay,
          0x7fffffe < ((iVar8 - uVar5) - 1 & 0xfffffff) ||
          (((iVar8 - 1U & 0xfffffff) == uVar5 && (*(uint *)(iVar4 + 8) <= extraout_a1_00))))))) {
    _r_co_list_extract_after = r_co_list_pop_front(&sch_arb_env);
    if (*(code **)(_r_co_list_extract_after + 0x18) != (code *)0x0) {
      (**(code **)(_r_co_list_extract_after + 0x18))();
    }
    iVar8 = ble_evt_kick_delay_get();
    iVar4 = _sch_arb_env;
    if (iVar8 != 0) {
      ble_evt_kick_delay_update(0);
      r_sch_prog_skip_isr(0xff);
      iVar4 = _sch_arb_env;
    }
  }
  if (_r_co_list_insert_after != 0) {
    r_rwip_sw_int_req();
  }
  uVar5 = r_rwip_time_get();
  uVar7 = extraout_a1 + 400;
  if (0x270 < uVar7) {
    uVar7 = extraout_a1 - 0xe1;
    uVar5 = uVar5 + 1 & 0xfffffff;
  }
  if (_sch_arb_env == 0) {
    r_rwip_timer_hus_set(0xffffffff,0);
    uVar3 = 0;
    uVar5 = 0xffffffff;
  }
  else {
    uVar2 = *(int *)(_sch_arb_env + 4) - (uint)rwip_prog_delay & 0xfffffff;
    uVar3 = uVar7;
    if ((((uVar2 - uVar5 & 0xfffffff) < 0x7ffffff) &&
        (uVar3 = *(uint *)(_sch_arb_env + 8), bVar1 = uVar2 == uVar5, uVar5 = uVar2, bVar1)) &&
       (uVar3 < uVar7)) {
      uVar3 = uVar7;
    }
    r_rwip_timer_hus_set(uVar5,uVar3);
  }
  iVar4 = r_sdk_config_get_opts_ext();
  if (((*(uint *)(iVar4 + 0x28) & 1) != 0) &&
     (iVar4 = r_sdk_config_get_opts_ext(), *(byte *)(iVar4 + 0x2c) < 2)) {
    r_ble_log_internal_x2(0x20040003,uVar5,uVar3);
    return;
  }
  return;
}

