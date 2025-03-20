/*
 * Last changed at upstream commit daab5dbba958a13041bd496e4a6ed506c9284a06
 * https://github.com/espressif/esp32c3-bt-lib/commit/daab5dbba958a13041bd496e4a6ed506c9284a06
 * Upstream date: 2025-03-20 20:43:40 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(86a4da5c)
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
  uint uVar3;
  undefined4 uVar4;
  int iVar5;
  int extraout_a1;
  uint extraout_a1_00;
  int iVar6;
  
  iVar5 = _sch_arb_env;
  uVar3 = r_rwip_time_get();
  while (iVar5 != 0) {
    iVar6 = *(int *)(iVar5 + 4) - (uint)rwip_prog_delay;
    if ((((1 - uVar3) + iVar6 & 0xfffffff) < 0x7ffffff) &&
       (((iVar6 + 1U & 0xfffffff) != uVar3 || (extraout_a1_00 <= *(uint *)(iVar5 + 8))))) {
      goto _L67;
    }
    iVar6 = r_sdk_config_get_opts_ext();
    if (((*(uint *)(iVar6 + 0x28) & 1) != 0) &&
       (iVar6 = r_sdk_config_get_opts_ext(), *(byte *)(iVar6 + 0x2c) < 3)) {
      r_ble_log_internal_x3(0x40040004,iVar5,*(undefined4 *)(iVar5 + 4),*(undefined4 *)(iVar5 + 8));
    }
    uVar4 = r_co_list_pop_front(&sch_arb_env);
    r_co_list_push_back(&sch_arb_env,uVar4);
    iVar5 = _sch_arb_env;
  }
  goto _L64;
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
_L67:
    iVar6 = *(int *)(iVar5 + 4) - (uint)rwip_prog_delay;
    if (((~uVar3 + iVar6 & 0xfffffff) < 0x7ffffff) &&
       (((iVar6 - 1U & 0xfffffff) != uVar3 || (extraout_a1_00 < *(uint *)(iVar5 + 8))))) break;
  }
_L64:
  if (_r_co_list_insert_after != 0) {
    r_rwip_sw_int_req();
  }
  uVar3 = r_rwip_time_get();
  uVar2 = extraout_a1 + 400;
  if (0x270 < uVar2) {
    uVar2 = extraout_a1 - 0xe1;
    uVar3 = uVar3 + 1 & 0xfffffff;
  }
  if (_sch_arb_env == 0) {
    r_rwip_timer_hus_set(0xffffffff,0);
    uVar2 = 0;
    uVar3 = 0xffffffff;
  }
  else {
    uVar1 = *(int *)(_sch_arb_env + 4) - (uint)rwip_prog_delay & 0xfffffff;
    if (((uVar1 - uVar3 & 0xfffffff) < 0x7ffffff) &&
       ((uVar1 != uVar3 || (uVar3 = uVar1, uVar2 < *(uint *)(_sch_arb_env + 8))))) {
      uVar3 = uVar1;
      uVar2 = *(uint *)(_sch_arb_env + 8);
    }
    r_rwip_timer_hus_set(uVar3,uVar2);
  }
  iVar5 = r_sdk_config_get_opts_ext();
  if (((*(uint *)(iVar5 + 0x28) & 1) != 0) &&
     (iVar5 = r_sdk_config_get_opts_ext(), *(byte *)(iVar5 + 0x2c) < 2)) {
    r_ble_log_internal_x2(0x20040003,uVar3,uVar2);
    return;
  }
  return;
}

