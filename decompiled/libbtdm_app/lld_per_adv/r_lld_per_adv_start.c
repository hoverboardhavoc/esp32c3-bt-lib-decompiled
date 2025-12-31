/*
 * Last changed at upstream commit 16cda80aab0a008093592b7e304c77dcb3ac9ea4
 * https://github.com/espressif/esp32c3-bt-lib/commit/16cda80aab0a008093592b7e304c77dcb3ac9ea4
 * Upstream date: 2025-12-31 14:03:52 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(1bb2f50)
 * Source: libbtdm_app -> lld_per_adv.o -> r_lld_per_adv_start
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1 r_lld_per_adv_start(uint param_1,ushort *param_2)

{
  ushort uVar1;
  undefined2 uVar2;
  ushort uVar3;
  int iVar4;
  void *__s;
  byte *pbVar5;
  int iVar6;
  byte bVar7;
  undefined4 uVar8;
  code *pcVar9;
  char cVar10;
  int iVar11;
  uint uVar12;
  uint *puVar13;
  uint uVar14;
  uint uVar15;
  undefined1 uStack_43;
  byte bStack_42;
  byte abStack_41 [13];
  
  uStack_43 = 0xc;
  iVar4 = (**(code **)(_r_ip_funcs_p + 0x84c))
                    (1,&uStack_43,param_1,param_2,*(code **)(_r_ip_funcs_p + 0x84c));
  if (iVar4 == 0) {
    if (*(int *)(&lld_per_adv_env + param_1 * 4) == 0) {
      __s = (void *)(**(code **)(_r_modules_funcs_p + 0x120))
                              (0x60,0,*(code **)(_r_modules_funcs_p + 0x120));
      *(void **)(&lld_per_adv_env + param_1 * 4) = __s;
      if (__s == (void *)0x0) {
        (**(code **)(_r_plf_funcs_p + 8))(0x10000,0x59e,*(code **)(_r_plf_funcs_p + 8));
      }
      else {
        bStack_42 = 0;
        abStack_41[0] = 0;
        memset(__s,0,0x60);
        iVar4 = _r_ip_funcs_p;
        *(undefined4 *)((int)__s + 0x20) = *(undefined4 *)(_r_ip_funcs_p + 0x2e0);
        uVar8 = *(undefined4 *)(iVar4 + 0x2e4);
        *(char *)((int)__s + 0x52) = (char)param_1;
        *(undefined4 *)((int)__s + 0x18) = uVar8;
        *(undefined1 *)((int)__s + 0x16) = DAT_0001301a;
        *(ushort *)((int)__s + 0x48) = param_2[1];
        *(uint *)((int)__s + 0x40) = (uint)*param_2 << 2;
        *(undefined2 *)((int)__s + 0x3a) = 10;
        *(char *)((int)__s + 0x54) = (char)param_2[5];
        *(undefined1 *)((int)__s + 0x56) = *(undefined1 *)((int)param_2 + 0xb);
        bVar7 = (byte)param_2[6];
        if ((bVar7 < 3) || (*(char *)(_p_lld_env + 0xda) == '\0')) {
          bVar7 = bVar7 - 1;
        }
        *(byte *)((int)__s + 0x55) = bVar7;
        iVar11 = _p_lld_env;
        *(ushort *)((int)__s + 0x50) = param_2[3];
        uVar1 = param_2[2];
        *(undefined1 *)((int)__s + 0x2f) = 0;
        *(undefined1 *)((int)__s + 0x30) = 0;
        *(ushort *)((int)__s + 0x4e) = uVar1;
        *(undefined1 *)((int)__s + 0x31) = 0;
        *(undefined1 *)((int)__s + 0x32) = 0;
        *(undefined1 *)((int)__s + 0x33) = 0;
        iVar6 = (uint)*(byte *)(iVar11 + 0x100) + iVar11;
        for (; iVar11 != iVar6; iVar11 = iVar11 + 1) {
          bVar7 = *(byte *)(iVar11 + 0xdb) >> 3;
          *(byte *)((int)__s + bVar7 + 0x2f) =
               (byte)(1 << (*(byte *)(iVar11 + 0xdb) & 7)) | *(byte *)((int)__s + bVar7 + 0x2f);
        }
        pcVar9 = *(code **)(iVar4 + 0x2c4);
        (*pcVar9)(param_1,pcVar9);
        (**(code **)(_r_modules_funcs_p + 0x1e0))
                  (6,param_1,&bStack_42,abStack_41,*(code **)(_r_modules_funcs_p + 0x1e0));
        uVar12 = (uint)bStack_42;
        uVar14 = (uint)rwip_coex_cfg;
        uVar15 = (uint)abStack_41[0];
        uVar1 = (ushort)rwip_coex_cfg;
        uVar3 = (ushort)rwip_coex_cfg;
        if ((uVar12 << 7 & 0xffffff7f) != 0) {
          (**(code **)(_r_plf_funcs_p + 8))(0,0x10000,0x42,*(code **)(_r_plf_funcs_p + 8));
        }
        if ((uVar15 << 6 & 0xffffffbf) != 0) {
          (**(code **)(_r_plf_funcs_p + 8))(0,0x10000,0x43,*(code **)(_r_plf_funcs_p + 8));
        }
        iVar11 = param_1 * 0x5a;
        iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
        *(ushort *)(iVar4 + iVar11) =
             (ushort)(uVar12 << 7) | (ushort)(uVar15 << 6) | (uVar3 & 4) << 6 |
             (ushort)((uVar14 & 1) << 10) | (uVar1 & 2) << 8 | 6;
        pbVar5 = (byte *)(**(code **)(_r_modules_funcs_p + 0x1a0))
                                   (4,*(code **)(_r_modules_funcs_p + 0x1a0));
        if (pbVar5 != (byte *)0x0) {
          bVar7 = pbVar5[1];
          if (0xb < param_1) {
            (**(code **)(_r_plf_funcs_p + 8))(0,0x10000,0x299b,*(code **)(_r_plf_funcs_p + 8));
          }
          if (((uint)bVar7 << 8 & 0xf000) != 0) {
            (**(code **)(_r_plf_funcs_p + 8))(0,0x10000,0x299d,*(code **)(_r_plf_funcs_p + 8));
          }
          puVar13 = (uint *)((param_1 + 0x1800c4cb) * 4);
          *puVar13 = *puVar13 & 0xfffff0ff | (uint)bVar7 << 8;
          bVar7 = *pbVar5;
          if (0xb < param_1) {
            (**(code **)(_r_plf_funcs_p + 8))(0,0x10000,0x294a,*(code **)(_r_plf_funcs_p + 8));
          }
          *puVar13 = (uint)bVar7 << 0x1e | *puVar13 & 0xbfffffff;
          bVar7 = pbVar5[3];
          if (0xb < param_1) {
            (**(code **)(_r_plf_funcs_p + 8))(0,0x10000,0x29bb,*(code **)(_r_plf_funcs_p + 8));
          }
          if ((bVar7 & 0xf0) != 0) {
            (**(code **)(_r_plf_funcs_p + 8))(0,0x10000,0x29bd,*(code **)(_r_plf_funcs_p + 8));
          }
          *puVar13 = *puVar13 & 0xfffffff0 | (uint)bVar7;
          bVar7 = pbVar5[2];
          if (0xb < param_1) {
            (**(code **)(_r_plf_funcs_p + 8))(0,0x10000,0x295a,*(code **)(_r_plf_funcs_p + 8));
          }
          *puVar13 = (uint)bVar7 << 0x1d | *puVar13 & 0xdfffffff;
          bVar7 = pbVar5[7];
          if (0xb < param_1) {
            (**(code **)(_r_plf_funcs_p + 8))(0,0x10000,0x298b,*(code **)(_r_plf_funcs_p + 8));
          }
          if (((uint)bVar7 << 0xc & 0xf0000) != 0) {
            (**(code **)(_r_plf_funcs_p + 8))(0,0x10000,0x298d,*(code **)(_r_plf_funcs_p + 8));
          }
          *puVar13 = *puVar13 & 0xffff0fff | (uint)bVar7 << 0xc;
          bVar7 = pbVar5[8];
          if (0xb < param_1) {
            (**(code **)(_r_plf_funcs_p + 8))(0,0x10000,0x29ab,*(code **)(_r_plf_funcs_p + 8));
          }
          if (((uint)bVar7 << 4 & 0xffffff0f) != 0) {
            (**(code **)(_r_plf_funcs_p + 8))(0,0x10000,0x29ad,*(code **)(_r_plf_funcs_p + 8));
          }
          *puVar13 = *puVar13 & 0xffffff0f | (uint)bVar7 << 4;
          bVar7 = pbVar5[9];
          if (0xb < param_1) {
            (**(code **)(_r_plf_funcs_p + 8))(0,0x10000,0x297b,*(code **)(_r_plf_funcs_p + 8));
          }
          if (((uint)bVar7 << 0x10 & 0xf00000) != 0) {
            (**(code **)(_r_plf_funcs_p + 8))(0,0x10000,0x297d,*(code **)(_r_plf_funcs_p + 8));
          }
          *puVar13 = *puVar13 & 0xfff0ffff | (uint)bVar7 << 0x10;
          uVar1 = *(ushort *)(pbVar5 + 10);
          if (0xb < param_1) {
            (**(code **)(_r_plf_funcs_p + 8))(0,0x10000,0x296a,*(code **)(_r_plf_funcs_p + 8));
          }
          if (((uint)uVar1 << 0x14 & 0xe0000000) != 0) {
            (**(code **)(_r_plf_funcs_p + 8))(0,0x10000,0x296c,*(code **)(_r_plf_funcs_p + 8));
          }
          *puVar13 = *puVar13 & 0xe00fffff | (uint)uVar1 << 0x14;
          bVar7 = pbVar5[6];
          if (0xb < param_1) {
            (**(code **)(_r_plf_funcs_p + 8))(0,0x10000,0x293a,*(code **)(_r_plf_funcs_p + 8));
          }
          *puVar13 = *puVar13 & 0x7fffffff | (uint)bVar7 << 0x1f;
          if (2 < _g_bt_plf_log_level) {
            ets_printf("PTI CNTL CS[%d] REG[%08x] TYPE[PER_ADV] RXEN[%d] RX[%d] IFSEN[%d] IFS[%d] PRTEN[%d] TIME[%d] DIFS[%d] DRX[%d] DTX[%d]\n"
                       ,param_1,puVar13,pbVar5[2],pbVar5[3],*pbVar5,pbVar5[1],pbVar5[6]);
          }
        }
        iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
        *(undefined2 *)(iVar11 + 0x16 + iVar4) = 0xc027;
        if (*(char *)((int)__s + 0x56) != '\x7f') {
          pcVar9 = *(code **)(_r_modules_funcs_p + 0x1fc);
          uVar8 = (*_memset)(0,_memset);
          (*pcVar9)(param_1,uVar8);
        }
        iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
        *(undefined2 *)(iVar11 + 0x18 + iVar4) = 0;
        (**(code **)(_r_ip_funcs_p + 0x304))(param_1,6,*(code **)(_r_ip_funcs_p + 0x304));
        uVar2 = *(undefined2 *)((int)__s + 0x2f);
        iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
        *(undefined2 *)(iVar11 + 0x22 + iVar4) = uVar2;
        uVar2 = *(undefined2 *)((int)__s + 0x31);
        iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
        *(undefined2 *)(iVar11 + 0x24 + iVar4) = uVar2;
        bVar7 = *(byte *)((int)__s + 0x33);
        iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
        *(ushort *)(iVar11 + 0x26 + iVar4) = (ushort)bVar7;
        (**(code **)(_r_ip_funcs_p + 0x220))
                  ((int)__s + 0x28,param_1,*(code **)(_r_ip_funcs_p + 0x220));
        uVar8 = (**(code **)(_r_osi_funcs_p + 0x88))(*(code **)(_r_osi_funcs_p + 0x88));
        iVar4 = _r_plf_funcs_p;
        *(short *)((int)__s + 0x2c) = (short)uVar8;
        *(char *)((int)__s + 0x2e) = (char)((uint)uVar8 >> 0x10);
        uVar2 = *(undefined2 *)((int)__s + 0x28);
        iVar4 = (**(code **)(iVar4 + 0xbc))(0x400,*(code **)(iVar4 + 0xbc));
        *(undefined2 *)(iVar11 + 0xc + iVar4) = uVar2;
        uVar2 = *(undefined2 *)((int)__s + 0x2a);
        iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
        *(undefined2 *)(iVar11 + 0xe + iVar4) = uVar2;
        uVar2 = *(undefined2 *)((int)__s + 0x2c);
        iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
        *(undefined2 *)(iVar11 + 0x10 + iVar4) = uVar2;
        bVar7 = *(byte *)((int)__s + 0x2e);
        iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
        *(ushort *)(iVar11 + 0x12 + iVar4) = (ushort)bVar7;
        iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
        *(undefined2 *)(iVar11 + 0x28 + iVar4) = 0;
        iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
        uVar12 = *(uint *)((int)__s + 0x44);
        *(undefined2 *)(iVar11 + 0x2a + iVar4) = 0;
        iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
        *(short *)(iVar11 + 0x20 + iVar4) = (short)((uVar12 / 0x271 + 1) * 0x10000 >> 0x10);
        bVar7 = *(byte *)((int)__s + 0x55);
        uVar12 = (uint)bVar7 << 4;
        if ((uVar12 & 0xffffffcf) != 0) {
          (**(code **)(_r_plf_funcs_p + 8))(0,0x10000,0x18e,*(code **)(_r_plf_funcs_p + 8));
        }
        uVar14 = (uint)bVar7 << 2;
        if ((uVar14 & 0xfffffff3) != 0) {
          (**(code **)(_r_plf_funcs_p + 8))(0,0x10000,399,*(code **)(_r_plf_funcs_p + 8));
        }
        if ((bVar7 & 0xfc) != 0) {
          (**(code **)(_r_plf_funcs_p + 8))(0,0x10000,400,*(code **)(_r_plf_funcs_p + 8));
        }
        iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
        *(ushort *)(iVar11 + 4 + iVar4) = (ushort)uVar12 | (ushort)uVar14 | (ushort)bVar7;
        uVar1 = param_2[5];
        if ((param_1 & 0xffffffe0) != 0) {
          (**(code **)(_r_plf_funcs_p + 8))(0,0x10000,0xe6,*(code **)(_r_plf_funcs_p + 8));
        }
        iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
        pcVar9 = *(code **)(_r_ip_funcs_p + 0x264);
        *(ushort *)(iVar11 + 2 + iVar4) = (ushort)(((byte)uVar1 & 1) << 7) | (ushort)param_1 | 0x800
        ;
        iVar4 = (*pcVar9)(pcVar9);
        uVar14 = *(uint *)((int)__s + 0x40);
        uVar12 = rwip_prog_delay + 1 + iVar4 & 0xfffffff;
        if (uVar14 == 0) {
          (**(code **)(_r_plf_funcs_p + 8))(0,0x10000,0x94,*(code **)(_r_plf_funcs_p + 8));
        }
        uVar1 = param_2[4];
        *(undefined4 *)((int)__s + 8) = 0;
        *(uint *)((int)__s + 4) = ((uint)uVar1 * 2 + uVar14 + uVar12) - uVar12 % uVar14 & 0xfffffff;
        bVar7 = DAT_0001301b;
        cVar10 = '\x0f';
        *(ushort *)((int)__s + 0x14) = DAT_0001301b & 0xf | 0x2000;
        do {
          iVar4 = (**(code **)(_r_ip_funcs_p + 0x6b0))(__s,*(code **)(_r_ip_funcs_p + 0x6b0));
          if (iVar4 == 0) {
            *(undefined1 *)((int)__s + 0x53) = 0;
            goto _L316;
          }
          cVar10 = cVar10 + -1;
          *(byte *)((int)__s + 0x16) = *(char *)((int)__s + 0x16) + bVar7;
          *(uint *)((int)__s + 4) = *(int *)((int)__s + 4) + *(int *)((int)__s + 0x40) & 0xfffffff;
        } while (cVar10 != '\0');
        (**(code **)(_r_plf_funcs_p + 8))(0,0x10000,0x594,*(code **)(_r_plf_funcs_p + 8));
_L316:
        (**(code **)(_r_ip_funcs_p + 0x2d0))(__s,*(code **)(_r_ip_funcs_p + 0x2d0));
        uStack_43 = 0;
      }
    }
    (**(code **)(_r_ip_funcs_p + 0x84c))
              (0,&uStack_43,param_1,param_2,*(code **)(_r_ip_funcs_p + 0x84c));
  }
  return uStack_43;
}

