/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> llc_con_upd.o -> r_llc_con_plan_set_update
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_llc_con_plan_set_update(int param_1,int param_2)

{
  ushort uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  ushort uStack_24;
  ushort uStack_22;
  
  iVar8 = *(int *)(&llc_env + param_1 * 4);
  iVar2 = r_llm_plan_elt_get();
  if (param_2 == 0) {
    uVar7 = 2;
  }
  else {
    uVar7 = (uint)*(ushort *)(param_2 + 0x10);
    if (uVar7 < 2) {
      uVar7 = 2;
    }
    uVar6 = (uint)*(ushort *)(param_2 + 0x12);
    if (1 < uVar6) goto _L69;
  }
  uVar6 = 2;
_L69:
  iVar3 = r_lld_con_offset_get(param_1);
  uVar4 = (uint)*(ushort *)(iVar8 + 0xe);
  uVar5 = uVar4 * 2;
  if (iVar2 == 0) {
    r_assert_err(0,"llc_con_upd.c",0x398);
  }
  if (uVar4 == 0) {
    r_assert_err(0,"llc_con_upd.c",0x399);
  }
  r_sch_plan_rem(iVar2);
  uVar1 = *(ushort *)(iVar8 + 0x42);
  *(uint *)(iVar2 + 4) = uVar5;
  *(int *)(iVar2 + 8) = iVar3;
  *(uint *)(iVar2 + 0xc) = uVar7;
  *(uint *)(iVar2 + 0x10) = uVar6;
  if ((uVar1 & 1) == 0) {
    if (uVar4 == 0) {
      r_assert_err(0,"llc_con_upd.c",0x94);
    }
    *(int *)(iVar2 + 0xc) = *(int *)(iVar2 + 0xc) + 3;
    *(int *)(iVar2 + 0x10) = *(int *)(iVar2 + 0x10) + 3;
    *(uint *)(iVar2 + 8) = ((uVar5 - 1) + iVar3) % uVar5;
  }
  iVar8 = r_sdk_config_get_opts();
  if (*(char *)(iVar8 + 0x15) == '\x01') {
    uVar4 = *(uint *)(iVar2 + 0x10);
    uVar6 = r_lld_con_evt_duration_min_get(param_1);
    uVar7 = uVar6 / 0x4e2;
    if (uVar6 / 0x4e2 < uVar4) {
      uVar7 = uVar4;
    }
    *(uint *)(iVar2 + 0x10) = uVar7;
    uVar4 = *(uint *)(iVar2 + 0xc);
    uVar6 = r_lld_con_evt_duration_min_get(param_1);
    uVar7 = uVar6 / 0x4e2;
    if (uVar6 / 0x4e2 < uVar4) {
      uVar7 = uVar4;
    }
    *(uint *)(iVar2 + 0xc) = uVar7;
  }
  else {
    iVar8 = r_sdk_config_get_opts();
    if ((*(char *)(iVar8 + 0x15) == '\x02') &&
       (iVar8 = r_lld_con_evt_sd_evt_time_get(param_1,&uStack_24,&uStack_22), iVar8 == 0)) {
      *(uint *)(iVar2 + 0x10) = (uint)uStack_24;
      *(uint *)(iVar2 + 0xc) = (uint)uStack_22;
    }
  }
  r_sch_plan_set(iVar2);
  return;
}

