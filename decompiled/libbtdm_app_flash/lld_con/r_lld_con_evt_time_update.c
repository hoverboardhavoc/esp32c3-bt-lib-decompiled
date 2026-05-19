/*
 * Last changed at upstream commit 7e73ebf92e5aa995065351043c13d2ac0f00772e
 * https://github.com/espressif/esp32c3-bt-lib/commit/7e73ebf92e5aa995065351043c13d2ac0f00772e
 * Upstream date: 2026-05-19 17:43:45 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(bc853c5)
 * Source: libbtdm_app_flash -> lld_con.o -> r_lld_con_evt_time_update
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_con_evt_time_update(int param_1)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  ushort uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  undefined2 uVar9;
  int iVar10;
  int iVar11;
  
  iVar2 = *(int *)(&lld_con_env + param_1 * 4);
  bVar1 = *(byte *)(iVar2 + 0x94);
  if ((bVar1 - 2 & 0xff) < 2) {
    uVar5 = *(ushort *)(iVar2 + 0x88);
    if (uVar5 < 0xa90) {
      uVar5 = 0xa90;
    }
    *(ushort *)(iVar2 + 0x88) = uVar5;
  }
  if ((byte)(*(char *)(iVar2 + 0x93) - 2U) < 2) {
    uVar5 = *(ushort *)(iVar2 + 0x8a);
    if (*(ushort *)(iVar2 + 0x8a) < 0xa90) {
      uVar5 = 0xa90;
    }
    *(ushort *)(iVar2 + 0x8a) = uVar5;
  }
  if (DAT_0001608b != '\0') {
    r_lld_con_evt_max_eff_time_cal(iVar2);
  }
  uVar7 = (uint)*(ushort *)(iVar2 + 0x88);
  uVar3 = (uint)*(ushort *)(iVar2 + 0x8a);
  iVar4 = uVar7 + 0x96 + uVar3;
  if (g_max_evt_env == '\0') {
    if (uVar7 < uVar3) {
      uVar7 = uVar3;
    }
    uVar7 = ((uVar7 + 0x95 + (uint)*(ushort *)(&fixed_tx_time + (uint)bVar1 * 2)) * 2) / 0x271 + 1
            >> 1;
  }
  else {
    uVar7 = (iVar4 + 0x306U) / 0x271;
  }
  uVar3 = (*(int *)(iVar2 + 100) - (uint)rwip_prog_delay) - 2 >> 1;
  if (uVar7 < uVar3) {
    if (g_max_evt_env == '\x02') {
      uVar8 = (uint)DAT_0001604d;
      if ((uVar8 != 0) && (uVar8 < uVar3)) {
        uVar3 = uVar3 - uVar8;
        goto _L100;
      }
    }
    uVar3 = uVar3 - uVar7;
  }
_L100:
  if ((*(ushort *)(iVar2 + 0x84) & 1) != 0) {
    uVar8 = (uint)*(ushort *)(iVar2 + 0x74);
    uVar3 = uVar3 - ((((uint)*(ushort *)(_p_lld_env + 0xd4) + (uint)*(ushort *)(iVar2 + 0x7a)) *
                     *(int *)(iVar2 + 100)) / 0x640 + 0x10) / 0x271;
    if ((uVar8 != 0) && (uVar8 < uVar3)) {
      uVar3 = uVar8;
    }
  }
  iVar4 = iVar4 * 2 + (uint)_DAT_00016082;
  *(int *)(iVar2 + 0x5c) = iVar4;
  *(int *)(iVar2 + 0x10) = iVar4;
  iVar4 = r_sdk_config_get_opts();
  iVar11 = param_1 * 0x5a + 0x20;
  iVar10 = param_1 * 0x5a + 0x1e;
  if (*(char *)(iVar4 + 0x15) == '\0') {
    iVar4 = r_emi_get_mem_addr_by_offset(0x400);
    *(short *)(iVar4 + iVar11) = (short)uVar3;
    iVar4 = r_emi_get_mem_addr_by_offset(0x400);
    *(short *)(iVar4 + iVar10) = (short)uVar3;
  }
  else {
    iVar4 = r_sdk_config_get_opts();
    if (*(char *)(iVar4 + 0x15) == '\x01') {
      iVar4 = r_llm_plan_elt_get(param_1);
      uVar7 = uVar3 * 0x4e2;
      if (*(uint *)(iVar2 + 0x5c) < uVar3 * 0x4e2) {
        uVar7 = *(uint *)(iVar2 + 0x5c);
      }
      *(uint *)(iVar2 + 0x5c) = uVar7;
      *(uint *)(iVar2 + 0x10) = uVar7;
      uVar7 = uVar7 / 0x4e2;
      uVar3 = uVar3 & 0xffff;
      if (iVar4 == 0) {
        uVar9 = (undefined2)uVar7;
      }
      else {
        uVar8 = *(uint *)(iVar4 + 0x10);
        if (uVar3 < *(uint *)(iVar4 + 0x10)) {
          uVar8 = uVar3;
        }
        if (uVar8 < uVar7) {
          uVar8 = uVar7;
        }
        uVar3 = uVar8 & 0xffff;
        uVar6 = *(uint *)(iVar4 + 0xc);
        if (*(uint *)(iVar4 + 0xc) < uVar7) {
          uVar6 = uVar7;
        }
        if ((uVar8 & 0xffff) < uVar6) {
          uVar6 = uVar8 & 0xffff;
        }
        uVar9 = (undefined2)uVar6;
        *(uint *)(iVar2 + 0x5c) = uVar6 * 0x4e2;
        *(uint *)(iVar2 + 0x10) = uVar6 * 0x4e2;
      }
    }
    else {
      uVar8 = (-2 - (uint)rwip_prog_delay) + *(int *)(iVar2 + 100) >> 1;
      if (*(ushort *)(iVar2 + 0x78) < uVar8) {
        uVar8 = (uint)*(ushort *)(iVar2 + 0x78);
      }
      uVar3 = uVar8 & 0xffff;
      uVar6 = (uint)*(ushort *)(iVar2 + 0x76);
      if (*(ushort *)(iVar2 + 0x76) < uVar7) {
        uVar6 = uVar7;
      }
      *(short *)(iVar2 + 0x78) = (short)uVar8;
      uVar9 = (undefined2)uVar6;
      *(undefined2 *)(iVar2 + 0x76) = uVar9;
      *(uint *)(iVar2 + 0x5c) = uVar6 * 0x4e2;
      *(uint *)(iVar2 + 0x10) = uVar6 * 0x4e2;
    }
    iVar4 = r_emi_get_mem_addr_by_offset(0x400);
    *(short *)(iVar4 + iVar11) = (short)uVar3;
    iVar4 = r_emi_get_mem_addr_by_offset(0x400);
    *(undefined2 *)(iVar4 + iVar10) = uVar9;
  }
  r_sch_slice_per_add(4,*(undefined1 *)(iVar2 + 0x8e),*(undefined4 *)(iVar2 + 100),
                      *(undefined2 *)(iVar2 + 0x10),0);
  return;
}

