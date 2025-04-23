/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> lld_sync.o -> r_lld_sync_sched
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_sync_sched(int param_1,char param_2)

{
  byte bVar1;
  ushort uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  code *pcVar8;
  uint uVar9;
  char cVar10;
  char acStack_41 [16];
  char acStack_31 [9];
  
  iVar3 = *(int *)(&lld_sync_env + param_1 * 4);
  acStack_31[0] = '\0';
  acStack_41[0] = param_2;
  do {
    bVar1 = DAT_0001302d;
    if (acStack_31[0] != '\0') {
      return;
    }
    cVar10 = lld_sync_max_aux_dur_tab;
    if (acStack_41[0] != '\0') {
      if (0xff < (uint)*(byte *)(iVar3 + 0x16) + (uint)DAT_0001302d) {
        (**(code **)(_r_plf_funcs_p + 8))(0,0x10000,0x337,*(code **)(_r_plf_funcs_p + 8));
      }
      cVar10 = bVar1 + *(char *)(iVar3 + 0x16);
    }
    *(char *)(iVar3 + 0x16) = cVar10;
    iVar7 = 1;
    if (*(char *)(iVar3 + 99) == '\x01') {
      uVar4 = *(uint *)(iVar3 + 0x2c);
      bVar1 = *(byte *)(iVar3 + 0x31);
      iVar7 = (int)*(short *)(iVar3 + 0x28);
      uVar5 = *(uint *)(iVar3 + 0x24);
    }
    else {
      if ((((*(char *)(iVar3 + 100) != '\0') && (*(char *)(iVar3 + 0x62) == '\0')) &&
          (*(ushort *)(iVar3 + 0x4c) != 0)) && (iVar7 = -1, acStack_41[0] == '\0')) {
        iVar6 = *(ushort *)(iVar3 + 0x4c) + 1;
        iVar7 = iVar6 * 0x10000 >> 0x10;
        *(short *)(iVar3 + 0x4e) = (short)iVar6 + *(short *)(iVar3 + 0x4a);
      }
      iVar6 = _r_ip_funcs_p;
      *(short *)(iVar3 + 0x4a) = *(short *)(iVar3 + 0x4a) + (short)iVar7;
      pcVar8 = *(code **)(iVar6 + 0x264);
      *(uint *)(iVar3 + 0x44) = iVar7 * *(int *)(iVar3 + 0x40) + *(int *)(iVar3 + 0x44) & 0xfffffff;
      iVar7 = (*pcVar8)(pcVar8);
      if ((((uint)rwip_prog_delay * 2 - *(int *)(iVar3 + 0x44)) + iVar7 & 0xfffffff) < 0x8000001) {
        iVar7 = (**(code **)(_r_ip_funcs_p + 0x264))();
        uVar4 = iVar7 + ((uint)rwip_prog_delay * 2 - *(int *)(iVar3 + 0x44)) & 0xfffffff;
        if (uVar4 != 0) {
          uVar2 = *(ushort *)(iVar3 + 0x4a);
          uVar5 = *(uint *)(iVar3 + 0x40);
          if (((uint)uVar2 - (uint)*(ushort *)(iVar3 + 0x4e) & 0xffff) < 0x7fff) {
            iVar7 = ((uVar5 - 1) + uVar4) / uVar5 << 0x10;
          }
          else {
            iVar7 = ((*(ushort *)(iVar3 + 0x4e) + 1) - (uint)uVar2) * 0x10000;
            *(undefined1 *)(iVar3 + 100) = 0;
          }
          *(ushort *)(iVar3 + 0x4a) = uVar2 + (short)((uint)iVar7 >> 0x10);
          *(uint *)(iVar3 + 0x44) = (iVar7 >> 0x10) * uVar5 + *(int *)(iVar3 + 0x44) & 0xfffffff;
        }
      }
      else {
        (**(code **)(_r_ip_funcs_p + 0x264))();
      }
      if (*(char *)(iVar3 + 0x57) == '\0') {
        uVar4 = *(int *)(iVar3 + 0x40) * 6;
      }
      else {
        uVar4 = *(uint *)(iVar3 + 0x34);
      }
      if (uVar4 < (*(int *)(iVar3 + 0x44) - *(int *)(iVar3 + 0x3c) & 0xfffffffU)) {
_L188:
        (**(code **)(_r_ip_funcs_p + 0x13c))(param_1,8,*(code **)(_r_ip_funcs_p + 0x13c));
        return;
      }
      iVar7 = (**(code **)(_r_modules_funcs_p + 0x28c))(*(code **)(_r_modules_funcs_p + 0x28c));
      uVar4 = 0x14;
      if (iVar7 == 0) {
        uVar4 = (uint)*(ushort *)(_p_lld_env + 0xd4);
      }
      iVar7 = (((uint)(*(int *)(iVar3 + 0x44) - *(int *)(iVar3 + 0x38)) >> 4 & 0xffffff) *
              (*(ushort *)(&co_sca2ppm + (uint)*(byte *)(iVar3 + 0x5a) * 2) + uVar4)) / 100 + 0x10;
      uVar4 = iVar7 * 2;
      uVar5 = *(int *)(iVar3 + 0x44) - uVar4 / 0x271 & 0xfffffff;
      uVar9 = (uint)*(ushort *)(iVar3 + 0x48) + iVar7 * -2 + (uVar4 / 0x271) * 0x271;
      iVar7 = (int)(uVar9 * 0x10000) >> 0x10;
      if (iVar7 < 0) {
        uVar5 = uVar5 - 1 & 0xfffffff;
        iVar7 = (int)(((uVar9 & 0xffff) + 0x271) * 0x10000) >> 0x10;
      }
      if ((*(char *)(iVar3 + 0x57) == '\0') &&
         (uVar4 = uVar4 + (-(uint)(*(char *)(iVar3 + 0x56) == '\0') & 0xfffffef2) + 300,
         ((uint)(*(int *)(iVar3 + 0x40) * 0x271) >> 1) - 0x96 < uVar4 >> 1)) goto _L188;
      bVar1 = *(byte *)(iVar3 + 0x58);
      *(undefined2 *)(iVar3 + 0x52) = 0;
    }
    *(int *)(iVar3 + 8) = iVar7;
    *(uint *)(iVar3 + 4) = uVar5;
    uVar4 = (*(ushort *)(&lld_sync_max_aux_dur_tab + (uint)bVar1 * 2) + uVar4) * 2 +
            (uint)_sdk_cfg_priv_opts;
    if (400000 < uVar4) {
      uVar4 = 400000;
    }
    *(uint *)(iVar3 + 0x10) = uVar4;
    (**(code **)(_r_ip_funcs_p + 0x7a4))
              (param_1,acStack_41,acStack_31,*(code **)(_r_ip_funcs_p + 0x7a4));
  } while( true );
}

