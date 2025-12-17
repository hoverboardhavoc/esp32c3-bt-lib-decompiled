/*
 * Last changed at upstream commit 9b50531537e755792ac827d00d233eab499a0b37
 * https://github.com/espressif/esp32c3-bt-lib/commit/9b50531537e755792ac827d00d233eab499a0b37
 * Upstream date: 2025-12-17 10:51:37 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(5106725)
 * Source: libbtdm_app -> lld_con.o -> r_lld_con_evt_time_update
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_con_evt_time_update(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  ushort uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  undefined2 uVar10;
  int iVar11;
  
  iVar1 = *(int *)(&lld_con_env + param_1 * 4);
  if ((byte)(*(char *)(iVar1 + 0x94) - 2U) < 2) {
    uVar6 = *(ushort *)(iVar1 + 0x88);
    if (uVar6 < 0xa90) {
      uVar6 = 0xa90;
    }
    *(ushort *)(iVar1 + 0x88) = uVar6;
  }
  if ((byte)(*(char *)(iVar1 + 0x93) - 2U) < 2) {
    uVar6 = *(ushort *)(iVar1 + 0x8a);
    if (*(ushort *)(iVar1 + 0x8a) < 0xa90) {
      uVar6 = 0xa90;
    }
    *(ushort *)(iVar1 + 0x8a) = uVar6;
  }
  if (DAT_00016047 != '\0') {
    (**(code **)(_r_ip_funcs_p + 0x350))(iVar1,*(code **)(_r_ip_funcs_p + 0x350));
  }
  iVar2 = _r_plf_funcs_p;
  uVar7 = (uint)*(ushort *)(iVar1 + 0x88);
  uVar4 = (uint)*(ushort *)(iVar1 + 0x8a);
  iVar5 = uVar7 + 0x96 + uVar4;
  if (g_max_evt_env == '\0') {
    if (uVar7 < uVar4) {
      uVar7 = uVar4;
    }
    uVar7 = (((uint)*(ushort *)(&fixed_tx_time + (uint)*(byte *)(iVar1 + 0x94) * 2) + uVar7 + 0x95)
            * 2) / 0x271 + 1 >> 1;
  }
  else {
    uVar7 = (iVar5 + 0x306U) / 0x271;
  }
  uVar4 = (*(int *)(iVar1 + 100) - (uint)rwip_prog_delay) - 2 >> 1;
  if (uVar7 < uVar4) {
    if (g_max_evt_env == '\x02') {
      uVar9 = (uint)DAT_00016041;
      if ((uVar9 != 0) && (uVar9 < uVar4)) {
        uVar4 = uVar4 - uVar9;
        goto _L251;
      }
    }
    uVar4 = uVar4 - uVar7;
  }
_L251:
  if ((*(ushort *)(iVar1 + 0x84) & 1) != 0) {
    uVar4 = uVar4 - ((((uint)*(ushort *)(_p_lld_env + 0xd4) + (uint)*(ushort *)(iVar1 + 0x7a)) *
                     *(int *)(iVar1 + 100)) / 0x640 + 0x10) / 0x271;
    uVar9 = (uint)*(ushort *)(iVar1 + 0x74);
    if ((uVar9 != 0) && (uVar9 < uVar4)) {
      uVar4 = uVar9;
    }
  }
  iVar5 = iVar5 * 2 + (uint)_DAT_0001603e;
  *(int *)(iVar1 + 0x5c) = iVar5;
  *(int *)(iVar1 + 0x10) = iVar5;
  iVar2 = (**(code **)(iVar2 + 0x38))(*(code **)(iVar2 + 0x38));
  iVar11 = param_1 * 0x5a + 0x20;
  iVar5 = param_1 * 0x5a + 0x1e;
  if (*(char *)(iVar2 + 0x15) == '\0') {
    iVar3 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
    iVar2 = _r_plf_funcs_p;
    *(short *)(iVar3 + iVar11) = (short)uVar4;
    iVar2 = (**(code **)(iVar2 + 0xbc))(0x400,*(code **)(iVar2 + 0xbc));
    *(short *)(iVar2 + iVar5) = (short)uVar4;
  }
  else {
    iVar2 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38));
    if (*(char *)(iVar2 + 0x15) == '\x01') {
      iVar2 = (**(code **)(_r_ip_funcs_p + 0x4f0))(param_1,*(code **)(_r_ip_funcs_p + 0x4f0));
      uVar7 = uVar4 * 0x4e2;
      if (*(uint *)(iVar1 + 0x5c) < uVar4 * 0x4e2) {
        uVar7 = *(uint *)(iVar1 + 0x5c);
      }
      *(uint *)(iVar1 + 0x5c) = uVar7;
      *(uint *)(iVar1 + 0x10) = uVar7;
      uVar7 = uVar7 / 0x4e2;
      uVar4 = uVar4 & 0xffff;
      if (iVar2 == 0) {
        uVar10 = (undefined2)uVar7;
      }
      else {
        uVar9 = *(uint *)(iVar2 + 0x10);
        if (uVar4 < *(uint *)(iVar2 + 0x10)) {
          uVar9 = uVar4;
        }
        if (uVar9 < uVar7) {
          uVar9 = uVar7;
        }
        uVar4 = uVar9 & 0xffff;
        uVar8 = *(uint *)(iVar2 + 0xc);
        if (*(uint *)(iVar2 + 0xc) < uVar7) {
          uVar8 = uVar7;
        }
        if ((uVar9 & 0xffff) < uVar8) {
          uVar8 = uVar9 & 0xffff;
        }
        uVar10 = (undefined2)uVar8;
        *(uint *)(iVar1 + 0x5c) = uVar8 * 0x4e2;
        *(uint *)(iVar1 + 0x10) = uVar8 * 0x4e2;
      }
    }
    else {
      uVar9 = (-2 - (uint)rwip_prog_delay) + *(int *)(iVar1 + 100) >> 1;
      if (*(ushort *)(iVar1 + 0x78) < uVar9) {
        uVar9 = (uint)*(ushort *)(iVar1 + 0x78);
      }
      uVar4 = uVar9 & 0xffff;
      uVar8 = (uint)*(ushort *)(iVar1 + 0x76);
      if (*(ushort *)(iVar1 + 0x76) < uVar7) {
        uVar8 = uVar7;
      }
      *(short *)(iVar1 + 0x78) = (short)uVar9;
      uVar10 = (undefined2)uVar8;
      *(undefined2 *)(iVar1 + 0x76) = uVar10;
      *(uint *)(iVar1 + 0x5c) = uVar8 * 0x4e2;
      *(uint *)(iVar1 + 0x10) = uVar8 * 0x4e2;
    }
    iVar3 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
    iVar2 = _r_plf_funcs_p;
    *(short *)(iVar3 + iVar11) = (short)uVar4;
    iVar2 = (**(code **)(iVar2 + 0xbc))(0x400,*(code **)(iVar2 + 0xbc));
    *(undefined2 *)(iVar2 + iVar5) = uVar10;
  }
                    /* WARNING: Could not recover jumptable at 0x00011396. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_ip_funcs_p + 0x72c))
            (4,*(undefined1 *)(iVar1 + 0x8e),*(undefined4 *)(iVar1 + 100),
             *(undefined2 *)(iVar1 + 0x10),0,*(code **)(_r_ip_funcs_p + 0x72c));
  return;
}

