/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> lld_sync.o -> r_lld_sync_start
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint r_lld_sync_start(uint param_1,undefined4 *param_2)

{
  undefined1 uVar1;
  byte bVar2;
  ushort uVar3;
  ushort uVar4;
  byte bVar5;
  undefined2 uVar6;
  byte bVar7;
  byte bVar8;
  int iVar9;
  void *__s;
  byte *pbVar10;
  int iVar11;
  undefined4 uVar12;
  ushort uVar13;
  undefined4 uVar14;
  code *pcVar15;
  ushort *puVar16;
  uint *puVar17;
  uint uVar18;
  uint uVar19;
  int iVar20;
  uint uVar21;
  byte bStack_3a;
  byte abStack_39 [9];
  
  iVar9 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38));
  if ((param_1 < *(byte *)(iVar9 + 0xd)) && (*(int *)(&lld_sync_env + param_1 * 4) == 0)) {
    __s = (void *)(**(code **)(_r_modules_funcs_p + 0x120))
                            (0x70,0,*(code **)(_r_modules_funcs_p + 0x120));
    *(void **)(&lld_sync_env + param_1 * 4) = __s;
    if (__s != (void *)0x0) {
      puVar16 = (ushort *)*param_2;
      uVar1 = *(undefined1 *)((int)param_2 + 10);
      bStack_3a = 0;
      abStack_39[0] = 0;
      uVar18 = (uint)*puVar16 * ((-(uint)((char)puVar16[1] == '\0') & 0xfffffef2) + 300) * 2 +
               (uint)*(ushort *)(param_2 + 2);
      memset(__s,0,0x70);
      uVar12 = *(undefined4 *)(_r_ip_funcs_p + 0x140);
      uVar14 = *(undefined4 *)(_r_ip_funcs_p + 0x144);
      *(char *)((int)__s + 0x55) = (char)param_1;
      uVar3 = *(ushort *)((int)param_2 + 0xe);
      *(undefined4 *)((int)__s + 0x18) = uVar14;
      bVar2 = rwip_priority;
      uVar4 = puVar16[2];
      *(undefined4 *)((int)__s + 0x20) = uVar12;
      uVar21 = (uint)uVar4 * 4;
      uVar19 = (uint)uVar3 << 5;
      *(ushort *)((int)__s + 0x14) = bVar2 & 0xf | 0x2000;
      *(uint *)((int)__s + 0x34) = uVar19;
      *(uint *)((int)__s + 0x40) = uVar21;
      memcpy((void *)((int)__s + 0x5c),puVar16 + 3,5);
      *(undefined1 *)((int)__s + 0x58) = uVar1;
      *(undefined1 *)((int)__s + 0x5a) = *(undefined1 *)((int)puVar16 + 0xb);
      *(undefined1 *)((int)__s + 0x59) = *(undefined1 *)((int)param_2 + 0xb);
      iVar9 = param_2[1];
      *(int *)((int)__s + 0x38) = iVar9;
      *(char *)((int)__s + 0x56) = (char)puVar16[1];
      iVar20 = uVar19 / uVar21 - 6;
      uVar13 = (ushort)iVar20;
      uVar19 = uVar18 / 0x271 + iVar9 + (uint)uVar4 * -4 & 0xfffffff;
      *(uint *)((int)__s + 0x44) = uVar19;
      *(uint *)((int)__s + 0x3c) = uVar19;
      uVar3 = puVar16[10];
      *(ushort *)((int)__s + 0x4a) = uVar3 - 1;
      *(ushort *)((int)__s + 0x4e) = uVar3 - 1;
      *(short *)((int)__s + 0x48) = (short)(uVar18 % 0x271);
      if (iVar20 * 0x10000 < 0) {
        uVar13 = 0;
      }
      if ((uint)*(ushort *)(param_2 + 3) < (uint)(int)(short)uVar13) {
        uVar13 = *(ushort *)(param_2 + 3);
      }
      iVar20 = param_1 * 0x5a;
      *(ushort *)((int)__s + 0x4c) = uVar13;
      uVar3 = puVar16[6];
      iVar9 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      *(ushort *)(iVar20 + 0xc + iVar9) = uVar3;
      uVar3 = puVar16[7];
      iVar9 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      *(ushort *)(iVar20 + 0xe + iVar9) = uVar3;
      uVar3 = puVar16[8];
      iVar9 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      *(ushort *)(iVar20 + 0x10 + iVar9) = uVar3;
      uVar3 = puVar16[9];
      iVar9 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      *(ushort *)(iVar20 + 0x12 + iVar9) = (ushort)(byte)uVar3;
      iVar9 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      *(undefined2 *)(iVar20 + 0x14 + iVar9) = 0;
      iVar9 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      *(undefined2 *)(iVar20 + 0x28 + iVar9) = 0x3e72;
      (**(code **)(_r_modules_funcs_p + 0x1e0))
                (10,param_1,&bStack_3a,abStack_39,*(code **)(_r_modules_funcs_p + 0x1e0));
      bVar8 = abStack_39[0];
      bVar7 = bStack_3a;
      uVar19 = (uint)rwip_coex_cfg;
      bVar2 = rwip_coex_cfg >> 1;
      bVar5 = rwip_coex_cfg >> 2;
      if ((bStack_3a & 0xfe) != 0) {
        (**(code **)(_r_plf_funcs_p + 8))(0,0x10000,0x42,*(code **)(_r_plf_funcs_p + 8));
      }
      if ((bVar8 & 0xfe) != 0) {
        (**(code **)(_r_plf_funcs_p + 8))(0,0x10000,0x43,*(code **)(_r_plf_funcs_p + 8));
      }
      iVar9 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      *(ushort *)(iVar9 + iVar20) =
           (ushort)bVar7 << 7 | (ushort)bVar8 << 6 | (ushort)((bVar5 & 1) << 8) |
           (ushort)((uVar19 & 1) << 10) | (ushort)((bVar2 & 1) << 9) | 0x2a;
      pbVar10 = (byte *)(**(code **)(_r_modules_funcs_p + 0x1a0))
                                  (7,*(code **)(_r_modules_funcs_p + 0x1a0));
      if (pbVar10 != (byte *)0x0) {
        bVar2 = pbVar10[1];
        if (0xb < param_1) {
          (**(code **)(_r_plf_funcs_p + 8))(0,0x10000,0x299b,*(code **)(_r_plf_funcs_p + 8));
        }
        if ((bVar2 & 0xf0) != 0) {
          (**(code **)(_r_plf_funcs_p + 8))(0,0x10000,0x299d,*(code **)(_r_plf_funcs_p + 8));
        }
        puVar17 = (uint *)((param_1 + 0x1800c4cb) * 4);
        *puVar17 = *puVar17 & 0xfffff0ff | (uint)bVar2 << 8;
        bVar2 = *pbVar10;
        if (0xb < param_1) {
          (**(code **)(_r_plf_funcs_p + 8))(0,0x10000,0x294a,*(code **)(_r_plf_funcs_p + 8));
        }
        *puVar17 = *puVar17 & 0xbfffffff | (uint)bVar2 << 0x1e;
        bVar2 = pbVar10[3];
        if (0xb < param_1) {
          (**(code **)(_r_plf_funcs_p + 8))(0,0x10000,0x29bb,*(code **)(_r_plf_funcs_p + 8));
        }
        if (0xf < bVar2) {
          (**(code **)(_r_plf_funcs_p + 8))(0,0x10000,0x29bd,*(code **)(_r_plf_funcs_p + 8));
        }
        *puVar17 = *puVar17 & 0xfffffff0 | (uint)bVar2;
        bVar2 = pbVar10[2];
        if (0xb < param_1) {
          (**(code **)(_r_plf_funcs_p + 8))(0,0x10000,0x295a,*(code **)(_r_plf_funcs_p + 8));
        }
        *puVar17 = *puVar17 & 0xdfffffff | (uint)bVar2 << 0x1d;
        bVar2 = pbVar10[7];
        if (0xb < param_1) {
          (**(code **)(_r_plf_funcs_p + 8))(0,0x10000,0x298b,*(code **)(_r_plf_funcs_p + 8));
        }
        if ((bVar2 & 0xf0) != 0) {
          (**(code **)(_r_plf_funcs_p + 8))(0,0x10000,0x298d,*(code **)(_r_plf_funcs_p + 8));
        }
        *puVar17 = *puVar17 & 0xffff0fff | (uint)bVar2 << 0xc;
        bVar2 = pbVar10[8];
        if (0xb < param_1) {
          (**(code **)(_r_plf_funcs_p + 8))(0,0x10000,0x29ab,*(code **)(_r_plf_funcs_p + 8));
        }
        if ((bVar2 & 0xf0) != 0) {
          (**(code **)(_r_plf_funcs_p + 8))(0,0x10000,0x29ad,*(code **)(_r_plf_funcs_p + 8));
        }
        *puVar17 = *puVar17 & 0xffffff0f | (uint)bVar2 << 4;
        bVar2 = pbVar10[9];
        if (0xb < param_1) {
          (**(code **)(_r_plf_funcs_p + 8))(0,0x10000,0x297b,*(code **)(_r_plf_funcs_p + 8));
        }
        if ((bVar2 & 0xf0) != 0) {
          (**(code **)(_r_plf_funcs_p + 8))(0,0x10000,0x297d,*(code **)(_r_plf_funcs_p + 8));
        }
        *puVar17 = *puVar17 & 0xfff0ffff | (uint)bVar2 << 0x10;
        uVar3 = *(ushort *)(pbVar10 + 10);
        if (0xb < param_1) {
          (**(code **)(_r_plf_funcs_p + 8))(0,0x10000,0x296a,*(code **)(_r_plf_funcs_p + 8));
        }
        if ((uVar3 >> 9 & 7) != 0) {
          (**(code **)(_r_plf_funcs_p + 8))(0,0x10000,0x296c,*(code **)(_r_plf_funcs_p + 8));
        }
        *puVar17 = *puVar17 & 0xe00fffff | (uint)uVar3 << 0x14;
        bVar2 = pbVar10[6];
        if (0xb < param_1) {
          (**(code **)(_r_plf_funcs_p + 8))(0,0x10000,0x293a,*(code **)(_r_plf_funcs_p + 8));
        }
        *puVar17 = *puVar17 & 0x7fffffff | (uint)bVar2 << 0x1f;
        if (2 < _g_bt_plf_log_level) {
          ets_printf("PTI CNTL CS[%d] REG[%08x] TYPE[SYNC_SCAN]] RXEN[%d] RX[%d] IFSEN[%d] IFS[%d] PRTEN[%d] TIME[%d] DIFS[%d] DRX[%d] DTX[%d]\n"
                     ,param_1,puVar17,pbVar10[2],pbVar10[3],*pbVar10,pbVar10[1],pbVar10[6]);
        }
      }
      uVar6 = *(undefined2 *)((int)__s + 0x5c);
      iVar9 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      *(undefined2 *)(iVar20 + 0x22 + iVar9) = uVar6;
      uVar6 = *(undefined2 *)((int)__s + 0x5e);
      iVar9 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      *(undefined2 *)(iVar20 + 0x24 + iVar9) = uVar6;
      bVar2 = *(byte *)((int)__s + 0x60);
      if (0x1f < bVar2) {
        (**(code **)(_r_plf_funcs_p + 8))(0,0x10000,0x64d,*(code **)(_r_plf_funcs_p + 8));
      }
      iVar9 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      uVar3 = *(ushort *)(iVar9 + iVar20 + 0x26);
      iVar9 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      *(ushort *)(iVar9 + iVar20 + 0x26) = (ushort)bVar2 | uVar3 & 0xffe0;
      iVar9 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      *(undefined2 *)(iVar20 + 0x18 + iVar9) = 0;
      if (0x1f < param_1) {
        (**(code **)(_r_plf_funcs_p + 8))(0,0x10000,0xe6,*(code **)(_r_plf_funcs_p + 8));
      }
      iVar11 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      iVar9 = _r_osi_funcs_p;
      *(short *)(iVar20 + 2 + iVar11) = (short)param_1;
      (**(code **)(iVar9 + 0x14))(*(code **)(iVar9 + 0x14));
      (**(code **)(_r_ip_funcs_p + 0x16c))(param_1,0,*(code **)(_r_ip_funcs_p + 0x16c));
      (**(code **)(_r_osi_funcs_p + 0x18))(*(code **)(_r_osi_funcs_p + 0x18));
      iVar9 = _r_modules_funcs_p;
      *(undefined1 *)((int)__s + 0x65) = 0;
      uVar12 = (**(code **)(iVar9 + 0x2c4))(*(code **)(iVar9 + 0x2c4));
      *(undefined4 *)((int)__s + 0x68) = uVar12;
      *(undefined4 *)((int)__s + 0x6c) = uVar12;
      return param_1;
    }
    uVar12 = 0x5b4;
    pcVar15 = *(code **)(_r_plf_funcs_p + 8);
  }
  else {
    uVar12 = 0x5b9;
    pcVar15 = *(code **)(_r_plf_funcs_p + 8);
  }
  (*pcVar15)(0,0x10000,uVar12,pcVar15);
  return param_1;
}

