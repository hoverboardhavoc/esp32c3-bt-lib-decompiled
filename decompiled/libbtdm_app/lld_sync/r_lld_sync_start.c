/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
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
  undefined2 uVar5;
  int iVar6;
  void *__s;
  byte *pbVar7;
  undefined4 uVar8;
  ushort uVar9;
  undefined4 uVar10;
  code *pcVar11;
  ushort *puVar12;
  uint *puVar13;
  uint uVar14;
  uint uVar15;
  int iVar16;
  uint uVar17;
  byte bStack_3a;
  byte abStack_39 [9];
  
  iVar6 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38));
  if ((param_1 < *(byte *)(iVar6 + 0xd)) && (*(int *)(&lld_sync_env + param_1 * 4) == 0)) {
    __s = (void *)(**(code **)(_r_modules_funcs_p + 0x120))
                            (0x70,0,*(code **)(_r_modules_funcs_p + 0x120));
    *(void **)(&lld_sync_env + param_1 * 4) = __s;
    if (__s != (void *)0x0) {
      puVar12 = (ushort *)*param_2;
      iVar6 = 300;
      if ((char)puVar12[1] == '\0') {
        iVar6 = 0x1e;
      }
      uVar1 = *(undefined1 *)((int)param_2 + 10);
      bStack_3a = 0;
      abStack_39[0] = 0;
      uVar14 = (uint)*puVar12 * iVar6 * 2 + (uint)*(ushort *)(param_2 + 2);
      memset(__s,0,0x70);
      uVar8 = *(undefined4 *)(_r_ip_funcs_p + 0x140);
      uVar10 = *(undefined4 *)(_r_ip_funcs_p + 0x144);
      *(char *)((int)__s + 0x55) = (char)param_1;
      uVar3 = *(ushort *)((int)param_2 + 0xe);
      *(undefined4 *)((int)__s + 0x18) = uVar10;
      bVar2 = rwip_priority;
      uVar4 = puVar12[2];
      *(undefined4 *)((int)__s + 0x20) = uVar8;
      uVar17 = (uint)uVar4 * 4;
      uVar15 = (uint)uVar3 << 5;
      *(ushort *)((int)__s + 0x14) = bVar2 & 0xf | 0x2000;
      *(uint *)((int)__s + 0x34) = uVar15;
      *(uint *)((int)__s + 0x40) = uVar17;
      memcpy((void *)((int)__s + 0x5c),puVar12 + 3,5);
      *(undefined1 *)((int)__s + 0x58) = uVar1;
      *(undefined1 *)((int)__s + 0x5a) = *(undefined1 *)((int)puVar12 + 0xb);
      *(undefined1 *)((int)__s + 0x59) = *(undefined1 *)((int)param_2 + 0xb);
      iVar6 = param_2[1];
      *(int *)((int)__s + 0x38) = iVar6;
      *(char *)((int)__s + 0x56) = (char)puVar12[1];
      iVar16 = uVar15 / uVar17 - 6;
      uVar9 = (ushort)iVar16;
      uVar15 = uVar14 / 0x271 + iVar6 + (uint)uVar4 * -4 & 0xfffffff;
      *(uint *)((int)__s + 0x44) = uVar15;
      *(uint *)((int)__s + 0x3c) = uVar15;
      uVar3 = puVar12[10];
      *(ushort *)((int)__s + 0x4a) = uVar3 - 1;
      *(ushort *)((int)__s + 0x4e) = uVar3 - 1;
      *(short *)((int)__s + 0x48) = (short)(uVar14 % 0x271);
      if (iVar16 * 0x10000 < 0) {
        uVar9 = 0;
      }
      if ((uint)*(ushort *)(param_2 + 3) < (uint)(int)(short)uVar9) {
        uVar9 = *(ushort *)(param_2 + 3);
      }
      iVar16 = param_1 * 0x5a;
      *(ushort *)((int)__s + 0x4c) = uVar9;
      uVar3 = puVar12[6];
      iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      *(ushort *)(iVar16 + 0xc + iVar6) = uVar3;
      uVar3 = puVar12[7];
      iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      *(ushort *)(iVar16 + 0xe + iVar6) = uVar3;
      uVar3 = puVar12[8];
      iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      *(ushort *)(iVar16 + 0x10 + iVar6) = uVar3;
      uVar3 = puVar12[9];
      iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      *(ushort *)(iVar16 + 0x12 + iVar6) = (ushort)(byte)uVar3;
      iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      *(undefined2 *)(iVar16 + 0x14 + iVar6) = 0;
      iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      *(undefined2 *)(iVar16 + 0x28 + iVar6) = 0x3e72;
      (**(code **)(_r_modules_funcs_p + 0x1e0))
                (10,param_1,&bStack_3a,abStack_39,*(code **)(_r_modules_funcs_p + 0x1e0));
      uVar15 = (uint)rwip_coex_cfg;
      uVar14 = (uint)bStack_3a;
      uVar17 = (uint)abStack_39[0];
      uVar3 = (ushort)rwip_coex_cfg;
      uVar4 = (ushort)rwip_coex_cfg;
      if ((uVar14 << 7 & 0xffffff7f) != 0) {
        (**(code **)(_r_plf_funcs_p + 8))(0,0x10000,0x42,*(code **)(_r_plf_funcs_p + 8));
      }
      if ((uVar17 << 6 & 0xffffffbf) != 0) {
        (**(code **)(_r_plf_funcs_p + 8))(0,0x10000,0x43,*(code **)(_r_plf_funcs_p + 8));
      }
      iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      *(ushort *)(iVar6 + iVar16) =
           (ushort)(uVar14 << 7) | (ushort)(uVar17 << 6) | (uVar4 & 4) << 6 |
           (ushort)((uVar15 & 1) << 10) | (uVar3 & 2) << 8 | 0x2a;
      pbVar7 = (byte *)(**(code **)(_r_modules_funcs_p + 0x1a0))
                                 (7,*(code **)(_r_modules_funcs_p + 0x1a0));
      if (pbVar7 != (byte *)0x0) {
        bVar2 = pbVar7[1];
        if (0xb < param_1) {
          (**(code **)(_r_plf_funcs_p + 8))(0,0x10000,0x299b,*(code **)(_r_plf_funcs_p + 8));
        }
        if (((uint)bVar2 << 8 & 0xf000) != 0) {
          (**(code **)(_r_plf_funcs_p + 8))(0,0x10000,0x299d,*(code **)(_r_plf_funcs_p + 8));
        }
        puVar13 = (uint *)((param_1 + 0x1800c4cb) * 4);
        *puVar13 = *puVar13 & 0xfffff0ff | (uint)bVar2 << 8;
        bVar2 = *pbVar7;
        if (0xb < param_1) {
          (**(code **)(_r_plf_funcs_p + 8))(0,0x10000,0x294a,*(code **)(_r_plf_funcs_p + 8));
        }
        *puVar13 = (uint)bVar2 << 0x1e | *puVar13 & 0xbfffffff;
        bVar2 = pbVar7[3];
        if (0xb < param_1) {
          (**(code **)(_r_plf_funcs_p + 8))(0,0x10000,0x29bb,*(code **)(_r_plf_funcs_p + 8));
        }
        if ((bVar2 & 0xf0) != 0) {
          (**(code **)(_r_plf_funcs_p + 8))(0,0x10000,0x29bd,*(code **)(_r_plf_funcs_p + 8));
        }
        *puVar13 = *puVar13 & 0xfffffff0 | (uint)bVar2;
        bVar2 = pbVar7[2];
        if (0xb < param_1) {
          (**(code **)(_r_plf_funcs_p + 8))(0,0x10000,0x295a,*(code **)(_r_plf_funcs_p + 8));
        }
        *puVar13 = (uint)bVar2 << 0x1d | *puVar13 & 0xdfffffff;
        bVar2 = pbVar7[7];
        if (0xb < param_1) {
          (**(code **)(_r_plf_funcs_p + 8))(0,0x10000,0x298b,*(code **)(_r_plf_funcs_p + 8));
        }
        if (((uint)bVar2 << 0xc & 0xf0000) != 0) {
          (**(code **)(_r_plf_funcs_p + 8))(0,0x10000,0x298d,*(code **)(_r_plf_funcs_p + 8));
        }
        *puVar13 = *puVar13 & 0xffff0fff | (uint)bVar2 << 0xc;
        bVar2 = pbVar7[8];
        if (0xb < param_1) {
          (**(code **)(_r_plf_funcs_p + 8))(0,0x10000,0x29ab,*(code **)(_r_plf_funcs_p + 8));
        }
        if (((uint)bVar2 << 4 & 0xffffff0f) != 0) {
          (**(code **)(_r_plf_funcs_p + 8))(0,0x10000,0x29ad,*(code **)(_r_plf_funcs_p + 8));
        }
        *puVar13 = *puVar13 & 0xffffff0f | (uint)bVar2 << 4;
        bVar2 = pbVar7[9];
        if (0xb < param_1) {
          (**(code **)(_r_plf_funcs_p + 8))(0,0x10000,0x297b,*(code **)(_r_plf_funcs_p + 8));
        }
        if (((uint)bVar2 << 0x10 & 0xf00000) != 0) {
          (**(code **)(_r_plf_funcs_p + 8))(0,0x10000,0x297d,*(code **)(_r_plf_funcs_p + 8));
        }
        *puVar13 = *puVar13 & 0xfff0ffff | (uint)bVar2 << 0x10;
        uVar3 = *(ushort *)(pbVar7 + 10);
        if (0xb < param_1) {
          (**(code **)(_r_plf_funcs_p + 8))(0,0x10000,0x296a,*(code **)(_r_plf_funcs_p + 8));
        }
        if (((uint)uVar3 << 0x14 & 0xe0000000) != 0) {
          (**(code **)(_r_plf_funcs_p + 8))(0,0x10000,0x296c,*(code **)(_r_plf_funcs_p + 8));
        }
        *puVar13 = *puVar13 & 0xe00fffff | (uint)uVar3 << 0x14;
        bVar2 = pbVar7[6];
        if (0xb < param_1) {
          (**(code **)(_r_plf_funcs_p + 8))(0,0x10000,0x293a,*(code **)(_r_plf_funcs_p + 8));
        }
        *puVar13 = *puVar13 & 0x7fffffff | (uint)bVar2 << 0x1f;
        if (2 < _g_bt_plf_log_level) {
          ets_printf("PTI CNTL CS[%d] REG[%08x] TYPE[SYNC_SCAN]] RXEN[%d] RX[%d] IFSEN[%d] IFS[%d] PRTEN[%d] TIME[%d] DIFS[%d] DRX[%d] DTX[%d]\n"
                     ,param_1,puVar13,pbVar7[2],pbVar7[3],*pbVar7,pbVar7[1],pbVar7[6]);
        }
      }
      uVar5 = *(undefined2 *)((int)__s + 0x5c);
      iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      *(undefined2 *)(iVar16 + 0x22 + iVar6) = uVar5;
      uVar5 = *(undefined2 *)((int)__s + 0x5e);
      iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      *(undefined2 *)(iVar16 + 0x24 + iVar6) = uVar5;
      bVar2 = *(byte *)((int)__s + 0x60);
      if ((bVar2 & 0xe0) != 0) {
        (**(code **)(_r_plf_funcs_p + 8))(0,0x10000,0x64d,*(code **)(_r_plf_funcs_p + 8));
      }
      iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      uVar3 = *(ushort *)(iVar6 + iVar16 + 0x26);
      iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      pcVar11 = *(code **)(_r_plf_funcs_p + 0xbc);
      *(ushort *)(iVar6 + iVar16 + 0x26) = uVar3 & 0xffe0 | (ushort)bVar2;
      iVar6 = (*pcVar11)(0x400,pcVar11);
      *(undefined2 *)(iVar16 + 0x18 + iVar6) = 0;
      if ((param_1 & 0xffffffe0) != 0) {
        (**(code **)(_r_plf_funcs_p + 8))(0,0x10000,0xe6,*(code **)(_r_plf_funcs_p + 8));
      }
      iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      *(short *)(iVar16 + 2 + iVar6) = (short)param_1;
      (**(code **)(_r_osi_funcs_p + 0x14))(*(code **)(_r_osi_funcs_p + 0x14));
      (**(code **)(_r_ip_funcs_p + 0x16c))(param_1,0,*(code **)(_r_ip_funcs_p + 0x16c));
      (**(code **)(_r_osi_funcs_p + 0x18))(*(code **)(_r_osi_funcs_p + 0x18));
      iVar6 = _r_modules_funcs_p;
      *(undefined1 *)((int)__s + 0x65) = 0;
      uVar8 = (**(code **)(iVar6 + 0x2c4))(*(code **)(iVar6 + 0x2c4));
      *(undefined4 *)((int)__s + 0x68) = uVar8;
      *(undefined4 *)((int)__s + 0x6c) = uVar8;
      return param_1;
    }
    uVar8 = 0x5b4;
    pcVar11 = *(code **)(_r_plf_funcs_p + 8);
  }
  else {
    uVar8 = 0x5b9;
    pcVar11 = *(code **)(_r_plf_funcs_p + 8);
  }
  (*pcVar11)(0,0x10000,uVar8,pcVar11);
  return param_1;
}

