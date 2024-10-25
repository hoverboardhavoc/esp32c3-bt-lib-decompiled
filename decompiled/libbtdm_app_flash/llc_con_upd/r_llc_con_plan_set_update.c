/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> llc_con_upd.o -> r_llc_con_plan_set_update
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_llc_con_plan_set_update(int param_1,int param_2)

{
  ushort uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  ushort uStack_24;
  ushort uStack_22;
  
  iVar6 = *(int *)(&llc_env + param_1 * 4);
  iVar4 = r_llm_plan_elt_get();
  if (param_2 == 0) {
    uVar8 = 2;
  }
  else {
    uVar8 = (uint)*(ushort *)(param_2 + 0x10);
    if (uVar8 < 2) {
      uVar8 = 2;
    }
    uVar7 = (uint)*(ushort *)(param_2 + 0x12);
    if (1 < uVar7) goto _L71;
  }
  uVar7 = 2;
_L71:
  iVar5 = r_lld_con_offset_get(param_1);
  uVar2 = (uint)*(ushort *)(iVar6 + 0xe);
  uVar3 = uVar2 * 2;
  if (iVar4 == 0) {
    r_assert_err(0,"llc_con_upd.c",0x398);
  }
  if (uVar2 == 0) {
    r_assert_err(0,"llc_con_upd.c",0x399);
  }
  r_sch_plan_rem(iVar4);
  uVar1 = *(ushort *)(iVar6 + 0x42);
  *(uint *)(iVar4 + 4) = uVar3;
  *(int *)(iVar4 + 8) = iVar5;
  *(uint *)(iVar4 + 0xc) = uVar8;
  *(uint *)(iVar4 + 0x10) = uVar7;
  if ((uVar1 & 1) == 0) {
    if (uVar2 == 0) {
      r_assert_err(0,"llc_con_upd.c",0x94);
    }
    *(int *)(iVar4 + 0xc) = *(int *)(iVar4 + 0xc) + 3;
    *(int *)(iVar4 + 0x10) = *(int *)(iVar4 + 0x10) + 3;
    *(uint *)(iVar4 + 8) = ((uVar3 - 1) + iVar5) % uVar3;
  }
  iVar6 = r_sdk_config_get_opts();
  if (*(char *)(iVar6 + 0x15) == '\x01') {
    uVar7 = *(uint *)(iVar4 + 0x10);
    uVar2 = r_lld_con_evt_duration_min_get(param_1);
    uVar8 = uVar2 / 0x4e2;
    if (uVar2 / 0x4e2 < uVar7) {
      uVar8 = uVar7;
    }
    *(uint *)(iVar4 + 0x10) = uVar8;
    uVar7 = *(uint *)(iVar4 + 0xc);
    uVar2 = r_lld_con_evt_duration_min_get(param_1);
    uVar8 = uVar2 / 0x4e2;
    if (uVar2 / 0x4e2 < uVar7) {
      uVar8 = uVar7;
    }
    *(uint *)(iVar4 + 0xc) = uVar8;
  }
  else {
    iVar6 = r_sdk_config_get_opts();
    if ((*(char *)(iVar6 + 0x15) == '\x02') &&
       (iVar6 = r_lld_con_evt_sd_evt_time_get(param_1,&uStack_24,&uStack_22), iVar6 == 0)) {
      *(uint *)(iVar4 + 0x10) = (uint)uStack_24;
      *(uint *)(iVar4 + 0xc) = (uint)uStack_22;
    }
  }
  r_sch_plan_set(iVar4);
  return;
}

