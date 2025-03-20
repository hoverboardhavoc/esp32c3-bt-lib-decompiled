/*
 * Last changed at upstream commit d2414a5dd958b32ca53382b441d24d97a0345a55
 * https://github.com/espressif/esp32c3-bt-lib/commit/d2414a5dd958b32ca53382b441d24d97a0345a55
 * Upstream date: 2025-03-20 20:11:19 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(03d0f8a6)
 * Source: libbtdm_app_flash -> lld_con.o -> r_lld_con_evt_time_update
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_con_evt_time_update(int param_1)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  ushort uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  undefined2 uVar8;
  int iVar9;
  int iVar10;
  
  iVar1 = *(int *)(&lld_con_env + param_1 * 4);
  if ((byte)(*(char *)(iVar1 + 0x94) - 2U) < 2) {
    uVar4 = *(ushort *)(iVar1 + 0x88);
    if (uVar4 < 0xa90) {
      uVar4 = 0xa90;
    }
    *(ushort *)(iVar1 + 0x88) = uVar4;
  }
  if ((byte)(*(char *)(iVar1 + 0x93) - 2U) < 2) {
    uVar4 = *(ushort *)(iVar1 + 0x8a);
    if (*(ushort *)(iVar1 + 0x8a) < 0xa90) {
      uVar4 = 0xa90;
    }
    *(ushort *)(iVar1 + 0x8a) = uVar4;
  }
  if (DAT_00016087 != '\0') {
    r_lld_con_evt_max_eff_time_cal(iVar1);
  }
  uVar5 = (uint)*(ushort *)(iVar1 + 0x88);
  uVar2 = (uint)*(ushort *)(iVar1 + 0x8a);
  iVar3 = uVar5 + 0x96 + uVar2;
  if (g_max_evt_env == '\0') {
    if (uVar5 < uVar2) {
      uVar5 = uVar2;
    }
    uVar5 = (((uint)*(ushort *)(&fixed_tx_time + (uint)*(byte *)(iVar1 + 0x94) * 2) + uVar5 + 0x95)
            * 2) / 0x271 + 1 >> 1;
  }
  else {
    uVar5 = (iVar3 + 0x306U) / 0x271;
  }
  uVar2 = (*(int *)(iVar1 + 100) - (uint)rwip_prog_delay) - 2 >> 1;
  if (uVar5 < uVar2) {
    if (((g_max_evt_env == '\x02') && (uVar6 = (uint)DAT_00016049, uVar6 != 0)) && (uVar6 < uVar2))
    {
      uVar2 = uVar2 - uVar6;
    }
    else {
      uVar2 = uVar2 - uVar5;
    }
  }
  if ((*(ushort *)(iVar1 + 0x84) & 1) != 0) {
    uVar2 = uVar2 - ((((uint)*(ushort *)(_p_lld_env + 0xd4) + (uint)*(ushort *)(iVar1 + 0x7a)) *
                     *(int *)(iVar1 + 100)) / 0x640 + 0x10) / 0x271;
    uVar6 = (uint)*(ushort *)(iVar1 + 0x74);
    if ((uVar6 != 0) && (uVar6 < uVar2)) {
      uVar2 = uVar6;
    }
  }
  iVar3 = iVar3 * 2 + (uint)_DAT_0001607e;
  *(int *)(iVar1 + 0x5c) = iVar3;
  *(int *)(iVar1 + 0x10) = iVar3;
  iVar3 = r_sdk_config_get_opts();
  iVar10 = param_1 * 0x5a + 0x20;
  iVar9 = param_1 * 0x5a + 0x1e;
  if (*(char *)(iVar3 + 0x15) == '\0') {
    iVar3 = r_emi_get_mem_addr_by_offset(0x400);
    *(short *)(iVar3 + iVar10) = (short)uVar2;
    iVar3 = r_emi_get_mem_addr_by_offset(0x400);
    *(short *)(iVar3 + iVar9) = (short)uVar2;
  }
  else {
    iVar3 = r_sdk_config_get_opts();
    if (*(char *)(iVar3 + 0x15) == '\x01') {
      iVar3 = r_llm_plan_elt_get(param_1);
      uVar5 = uVar2 * 0x4e2;
      if (*(uint *)(iVar1 + 0x5c) < uVar2 * 0x4e2) {
        uVar5 = *(uint *)(iVar1 + 0x5c);
      }
      *(uint *)(iVar1 + 0x5c) = uVar5;
      *(uint *)(iVar1 + 0x10) = uVar5;
      uVar5 = uVar5 / 0x4e2;
      uVar2 = uVar2 & 0xffff;
      if (iVar3 == 0) {
        uVar8 = (undefined2)uVar5;
      }
      else {
        uVar6 = *(uint *)(iVar3 + 0x10);
        if (uVar2 < *(uint *)(iVar3 + 0x10)) {
          uVar6 = uVar2;
        }
        if (uVar6 < uVar5) {
          uVar6 = uVar5;
        }
        uVar2 = uVar6 & 0xffff;
        uVar7 = *(uint *)(iVar3 + 0xc);
        if (*(uint *)(iVar3 + 0xc) < uVar5) {
          uVar7 = uVar5;
        }
        if ((uVar6 & 0xffff) < uVar7) {
          uVar7 = uVar6 & 0xffff;
        }
        uVar8 = (undefined2)uVar7;
        *(uint *)(iVar1 + 0x5c) = uVar7 * 0x4e2;
        *(uint *)(iVar1 + 0x10) = uVar7 * 0x4e2;
      }
    }
    else {
      uVar6 = (-2 - (uint)rwip_prog_delay) + *(int *)(iVar1 + 100) >> 1;
      if (*(ushort *)(iVar1 + 0x78) < uVar6) {
        uVar6 = (uint)*(ushort *)(iVar1 + 0x78);
      }
      uVar2 = uVar6 & 0xffff;
      uVar7 = (uint)*(ushort *)(iVar1 + 0x76);
      if (*(ushort *)(iVar1 + 0x76) < uVar5) {
        uVar7 = uVar5;
      }
      *(short *)(iVar1 + 0x78) = (short)uVar6;
      uVar8 = (undefined2)uVar7;
      *(undefined2 *)(iVar1 + 0x76) = uVar8;
      *(uint *)(iVar1 + 0x5c) = uVar7 * 0x4e2;
      *(uint *)(iVar1 + 0x10) = uVar7 * 0x4e2;
    }
    iVar3 = r_emi_get_mem_addr_by_offset(0x400);
    *(short *)(iVar3 + iVar10) = (short)uVar2;
    iVar3 = r_emi_get_mem_addr_by_offset(0x400);
    *(undefined2 *)(iVar3 + iVar9) = uVar8;
  }
  r_sch_slice_per_add(4,*(undefined1 *)(iVar1 + 0x8e),*(undefined4 *)(iVar1 + 100),
                      *(undefined2 *)(iVar1 + 0x10),0);
  return;
}

