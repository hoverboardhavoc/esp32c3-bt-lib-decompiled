/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
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
  undefined2 uVar4;
  int iVar5;
  void *__s;
  byte *pbVar6;
  undefined4 uVar7;
  ushort uVar8;
  undefined4 uVar9;
  code *pcVar10;
  ushort *puVar11;
  uint *puVar12;
  uint uVar13;
  int iVar14;
  uint uVar15;
  int iVar16;
  uint uVar17;
  byte bStack_3a;
  byte abStack_39 [9];
  
  iVar5 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38));
  if ((param_1 < *(byte *)(iVar5 + 0xd)) && (*(int *)(&lld_sync_env + param_1 * 4) == 0)) {
    __s = (void *)(**(code **)(_r_modules_funcs_p + 0x120))
                            (0x70,0,*(code **)(_r_modules_funcs_p + 0x120));
    *(void **)(&lld_sync_env + param_1 * 4) = __s;
    if (__s != (void *)0x0) {
      puVar11 = (ushort *)*param_2;
      iVar5 = 300;
      if ((char)puVar11[1] == '\0') {
        iVar5 = 0x1e;
      }
      uVar1 = *(undefined1 *)((int)param_2 + 10);
      bStack_3a = 0;
      abStack_39[0] = 0;
      uVar15 = (uint)*puVar11 * iVar5 * 2 + (uint)*(ushort *)(param_2 + 2);
      memset(__s,0,0x70);
      uVar7 = *(undefined4 *)(_r_ip_funcs_p + 0x140);
      uVar9 = *(undefined4 *)(_r_ip_funcs_p + 0x144);
      *(char *)((int)__s + 0x55) = (char)param_1;
      uVar8 = *(ushort *)((int)param_2 + 0xe);
      *(undefined4 *)((int)__s + 0x18) = uVar9;
      bVar2 = rwip_priority;
      uVar3 = puVar11[2];
      *(undefined4 *)((int)__s + 0x20) = uVar7;
      uVar17 = (uint)uVar3 * 4;
      uVar13 = (uint)uVar8 << 5;
      *(ushort *)((int)__s + 0x14) = bVar2 & 0xf | 0x2000;
      *(uint *)((int)__s + 0x34) = uVar13;
      *(undefined4 *)((int)__s + 0x1c) = 0;
      *(uint *)((int)__s + 0x40) = uVar17;
      memcpy((void *)((int)__s + 0x5c),puVar11 + 3,5);
      *(undefined1 *)((int)__s + 0x58) = uVar1;
      *(undefined1 *)((int)__s + 0x5a) = *(undefined1 *)((int)puVar11 + 0xb);
      *(undefined1 *)((int)__s + 0x59) = *(undefined1 *)((int)param_2 + 0xb);
      iVar5 = param_2[1];
      *(undefined1 *)((int)__s + 0x57) = 0;
      *(int *)((int)__s + 0x38) = iVar5;
      *(char *)((int)__s + 0x56) = (char)puVar11[1];
      iVar14 = (int)((uVar13 / uVar17 - 6) * 0x10000) >> 0x10;
      uVar13 = uVar15 / 0x271 + iVar5 + (uint)uVar3 * -4 & 0xfffffff;
      *(uint *)((int)__s + 0x44) = uVar13;
      *(uint *)((int)__s + 0x3c) = uVar13;
      uVar8 = puVar11[10];
      *(undefined1 *)((int)__s + 100) = 0;
      *(undefined1 *)((int)__s + 99) = 0;
      *(ushort *)((int)__s + 0x4a) = uVar8 - 1;
      *(ushort *)((int)__s + 0x4e) = uVar8 - 1;
      *(undefined1 *)((int)__s + 0x61) = 0;
      uVar8 = *(ushort *)(param_2 + 3);
      *(short *)((int)__s + 0x48) = (short)(uVar15 % 0x271);
      if (iVar14 < 0) {
        iVar14 = 0;
      }
      if ((uint)(int)(short)(ushort)iVar14 < (uint)uVar8) {
        uVar8 = (ushort)iVar14;
      }
      *(ushort *)((int)__s + 0x4c) = uVar8;
      iVar16 = param_1 * 0x5a;
      uVar8 = puVar11[6];
      iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      *(ushort *)(iVar5 + iVar16 + 0xc) = uVar8;
      uVar8 = puVar11[7];
      iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      *(ushort *)(iVar5 + iVar16 + 0xe) = uVar8;
      uVar8 = puVar11[8];
      iVar14 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      iVar5 = _r_plf_funcs_p;
      *(ushort *)(iVar14 + iVar16 + 0x10) = uVar8;
      uVar8 = puVar11[9];
      iVar5 = (**(code **)(iVar5 + 0xbc))(0x400,*(code **)(iVar5 + 0xbc));
      pcVar10 = *(code **)(_r_plf_funcs_p + 0xbc);
      *(ushort *)(iVar5 + iVar16 + 0x12) = (ushort)(byte)uVar8;
      iVar14 = (*pcVar10)(0x400,pcVar10);
      iVar5 = _r_plf_funcs_p;
      *(undefined2 *)(iVar14 + iVar16 + 0x14) = 0;
      iVar5 = (**(code **)(iVar5 + 0xbc))(0x400,*(code **)(iVar5 + 0xbc));
      *(undefined2 *)(iVar5 + iVar16 + 0x28) = 0x3e72;
      (**(code **)(_r_modules_funcs_p + 0x1e0))
                (10,param_1,&bStack_3a,abStack_39,*(code **)(_r_modules_funcs_p + 0x1e0));
      uVar13 = (uint)rwip_coex_cfg;
      uVar15 = (uint)bStack_3a;
      uVar17 = (uint)abStack_39[0];
      uVar8 = (ushort)rwip_coex_cfg;
      uVar3 = (ushort)rwip_coex_cfg;
      if ((uVar15 << 7 & 0xffffff7f) != 0) {
        (**(code **)(_r_plf_funcs_p + 8))(0,"lld_sync.c",0x42,*(code **)(_r_plf_funcs_p + 8));
      }
      if ((uVar17 << 6 & 0xffffffbf) != 0) {
        (**(code **)(_r_plf_funcs_p + 8))(0,"lld_sync.c",0x43,*(code **)(_r_plf_funcs_p + 8));
      }
      iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      *(ushort *)(iVar5 + iVar16) =
           (ushort)(uVar15 << 7) | (ushort)(uVar17 << 6) | (uVar3 & 4) << 6 |
           (ushort)((uVar13 & 1) << 10) | (uVar8 & 2) << 8 | 0x2a;
      pbVar6 = (byte *)(**(code **)(_r_modules_funcs_p + 0x1a0))
                                 (7,*(code **)(_r_modules_funcs_p + 0x1a0));
      if (pbVar6 != (byte *)0x0) {
        bVar2 = pbVar6[1];
        if (0xb < param_1) {
          (**(code **)(_r_plf_funcs_p + 8))(0,"lld_sync.c",0x299b,*(code **)(_r_plf_funcs_p + 8));
        }
        if (((uint)bVar2 << 8 & 0xf000) != 0) {
          (**(code **)(_r_plf_funcs_p + 8))(0,"lld_sync.c",0x299d,*(code **)(_r_plf_funcs_p + 8));
        }
        puVar12 = (uint *)((param_1 + 0x1800c4cb) * 4);
        *puVar12 = *puVar12 & 0xfffff0ff | (uint)bVar2 << 8;
        bVar2 = *pbVar6;
        if (0xb < param_1) {
          (**(code **)(_r_plf_funcs_p + 8))(0,"lld_sync.c",0x294a,*(code **)(_r_plf_funcs_p + 8));
        }
        *puVar12 = (uint)bVar2 << 0x1e | *puVar12 & 0xbfffffff;
        bVar2 = pbVar6[3];
        if (0xb < param_1) {
          (**(code **)(_r_plf_funcs_p + 8))(0,"lld_sync.c",0x29bb,*(code **)(_r_plf_funcs_p + 8));
        }
        if ((bVar2 & 0xf0) != 0) {
          (**(code **)(_r_plf_funcs_p + 8))(0,"lld_sync.c",0x29bd,*(code **)(_r_plf_funcs_p + 8));
        }
        *puVar12 = *puVar12 & 0xfffffff0 | (uint)bVar2;
        bVar2 = pbVar6[2];
        if (0xb < param_1) {
          (**(code **)(_r_plf_funcs_p + 8))(0,"lld_sync.c",0x295a,*(code **)(_r_plf_funcs_p + 8));
        }
        *puVar12 = (uint)bVar2 << 0x1d | *puVar12 & 0xdfffffff;
        bVar2 = pbVar6[7];
        if (0xb < param_1) {
          (**(code **)(_r_plf_funcs_p + 8))(0,"lld_sync.c",0x298b,*(code **)(_r_plf_funcs_p + 8));
        }
        if (((uint)bVar2 << 0xc & 0xf0000) != 0) {
          (**(code **)(_r_plf_funcs_p + 8))(0,"lld_sync.c",0x298d,*(code **)(_r_plf_funcs_p + 8));
        }
        *puVar12 = *puVar12 & 0xffff0fff | (uint)bVar2 << 0xc;
        bVar2 = pbVar6[8];
        if (0xb < param_1) {
          (**(code **)(_r_plf_funcs_p + 8))(0,"lld_sync.c",0x29ab,*(code **)(_r_plf_funcs_p + 8));
        }
        if (((uint)bVar2 << 4 & 0xffffff0f) != 0) {
          (**(code **)(_r_plf_funcs_p + 8))(0,"lld_sync.c",0x29ad,*(code **)(_r_plf_funcs_p + 8));
        }
        *puVar12 = *puVar12 & 0xffffff0f | (uint)bVar2 << 4;
        bVar2 = pbVar6[9];
        if (0xb < param_1) {
          (**(code **)(_r_plf_funcs_p + 8))(0,"lld_sync.c",0x297b,*(code **)(_r_plf_funcs_p + 8));
        }
        if (((uint)bVar2 << 0x10 & 0xf00000) != 0) {
          (**(code **)(_r_plf_funcs_p + 8))(0,"lld_sync.c",0x297d,*(code **)(_r_plf_funcs_p + 8));
        }
        *puVar12 = *puVar12 & 0xfff0ffff | (uint)bVar2 << 0x10;
        uVar8 = *(ushort *)(pbVar6 + 10);
        if (0xb < param_1) {
          (**(code **)(_r_plf_funcs_p + 8))(0,"lld_sync.c",0x296a,*(code **)(_r_plf_funcs_p + 8));
        }
        if (((uint)uVar8 << 0x14 & 0xe0000000) != 0) {
          (**(code **)(_r_plf_funcs_p + 8))(0,"lld_sync.c",0x296c,*(code **)(_r_plf_funcs_p + 8));
        }
        *puVar12 = *puVar12 & 0xe00fffff | (uint)uVar8 << 0x14;
        bVar2 = pbVar6[6];
        if (0xb < param_1) {
          (**(code **)(_r_plf_funcs_p + 8))(0,"lld_sync.c",0x293a,*(code **)(_r_plf_funcs_p + 8));
        }
        *puVar12 = *puVar12 & 0x7fffffff | (uint)bVar2 << 0x1f;
        if (2 < _g_bt_plf_log_level) {
          ets_printf("PTI CNTL CS[%d] REG[%08x] TYPE[SYNC_SCAN]] RXEN[%d] RX[%d] IFSEN[%d] IFS[%d] PRTEN[%d] TIME[%d] DIFS[%d] DRX[%d] DTX[%d]\n"
                     ,param_1,puVar12,pbVar6[2],pbVar6[3],*pbVar6,pbVar6[1],pbVar6[6]);
        }
      }
      uVar4 = *(undefined2 *)((int)__s + 0x5c);
      iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      *(undefined2 *)(iVar5 + iVar16 + 0x22) = uVar4;
      uVar4 = *(undefined2 *)((int)__s + 0x5e);
      iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      *(undefined2 *)(iVar5 + iVar16 + 0x24) = uVar4;
      bVar2 = *(byte *)((int)__s + 0x60);
      if ((bVar2 & 0xe0) != 0) {
        (**(code **)(_r_plf_funcs_p + 8))(0,"lld_sync.c",0x64d,*(code **)(_r_plf_funcs_p + 8));
      }
      iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      uVar8 = *(ushort *)(iVar5 + iVar16 + 0x26);
      iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      pcVar10 = *(code **)(_r_plf_funcs_p + 0xbc);
      *(ushort *)(iVar5 + iVar16 + 0x26) = uVar8 & 0xffe0 | (ushort)bVar2;
      iVar5 = (*pcVar10)(0x400,pcVar10);
      *(undefined2 *)(iVar5 + iVar16 + 0x18) = 0;
      if ((param_1 & 0xffffffe0) != 0) {
        (**(code **)(_r_plf_funcs_p + 8))(0,"lld_sync.c",0xe6,*(code **)(_r_plf_funcs_p + 8));
      }
      iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      *(short *)(iVar16 + 2 + iVar5) = (short)param_1;
      (**(code **)(_r_osi_funcs_p + 0x14))(*(code **)(_r_osi_funcs_p + 0x14));
      (**(code **)(_r_ip_funcs_p + 0x16c))(param_1,0,*(code **)(_r_ip_funcs_p + 0x16c));
      (**(code **)(_r_osi_funcs_p + 0x18))(*(code **)(_r_osi_funcs_p + 0x18));
      iVar5 = _r_modules_funcs_p;
      *(undefined1 *)((int)__s + 0x65) = 0;
      uVar7 = (**(code **)(iVar5 + 0x2c4))(*(code **)(iVar5 + 0x2c4));
      *(undefined4 *)((int)__s + 0x68) = uVar7;
      *(undefined4 *)((int)__s + 0x6c) = uVar7;
      return param_1;
    }
    uVar7 = 0x59d;
    pcVar10 = *(code **)(_r_plf_funcs_p + 8);
  }
  else {
    uVar7 = 0x5a2;
    pcVar10 = *(code **)(_r_plf_funcs_p + 8);
  }
  (*pcVar10)(0,"lld_sync.c",uVar7,pcVar10);
  return param_1;
}

