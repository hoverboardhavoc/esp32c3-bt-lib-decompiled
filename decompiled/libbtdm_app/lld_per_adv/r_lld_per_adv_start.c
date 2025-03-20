/*
 * Last changed at upstream commit d2414a5dd958b32ca53382b441d24d97a0345a55
 * https://github.com/espressif/esp32c3-bt-lib/commit/d2414a5dd958b32ca53382b441d24d97a0345a55
 * Upstream date: 2025-03-20 20:11:19 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(03d0f8a6)
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
  ushort uVar2;
  undefined2 uVar3;
  undefined1 uVar4;
  int iVar5;
  void *__s;
  byte *pbVar6;
  int iVar7;
  byte bVar8;
  undefined4 uVar9;
  code *pcVar10;
  int iVar11;
  char cVar12;
  uint uVar13;
  uint *puVar14;
  uint uVar15;
  uint uVar16;
  undefined1 uStack_43;
  byte bStack_42;
  byte abStack_41 [13];
  
  uStack_43 = 0xc;
  iVar5 = (**(code **)(_r_ip_funcs_p + 0x84c))
                    (1,&uStack_43,param_1,param_2,*(code **)(_r_ip_funcs_p + 0x84c));
  if (iVar5 == 0) {
    if (*(int *)(&lld_per_adv_env + param_1 * 4) == 0) {
      __s = (void *)(**(code **)(_r_modules_funcs_p + 0x120))
                              (0x60,0,*(code **)(_r_modules_funcs_p + 0x120));
      *(void **)(&lld_per_adv_env + param_1 * 4) = __s;
      if (__s == (void *)0x0) {
        (**(code **)(_r_plf_funcs_p + 8))("lld_per_adv.c",0x587,*(code **)(_r_plf_funcs_p + 8));
      }
      else {
        bStack_42 = 0;
        abStack_41[0] = 0;
        memset(__s,0,0x60);
        iVar5 = _r_ip_funcs_p;
        *(undefined4 *)((int)__s + 0x20) = *(undefined4 *)(_r_ip_funcs_p + 0x2e0);
        uVar9 = *(undefined4 *)(iVar5 + 0x2e4);
        *(char *)((int)__s + 0x52) = (char)param_1;
        *(undefined4 *)((int)__s + 0x1c) = 0;
        *(undefined4 *)((int)__s + 0x18) = uVar9;
        uVar4 = DAT_0001301a;
        *(undefined4 *)((int)__s + 8) = 0;
        *(undefined1 *)((int)__s + 0x16) = uVar4;
        *(ushort *)((int)__s + 0x48) = param_2[1];
        uVar1 = *param_2;
        *(undefined2 *)((int)__s + 0x4c) = 0;
        *(uint *)((int)__s + 0x40) = (uint)uVar1 << 2;
        *(undefined2 *)((int)__s + 0x3a) = 10;
        *(char *)((int)__s + 0x54) = (char)param_2[5];
        *(undefined1 *)((int)__s + 0x56) = *(undefined1 *)((int)param_2 + 0xb);
        bVar8 = (byte)param_2[6];
        if ((bVar8 < 3) || (*(char *)(_p_lld_env + 0xda) == '\0')) {
          bVar8 = bVar8 - 1;
        }
        *(byte *)((int)__s + 0x55) = bVar8;
        iVar11 = _p_lld_env;
        *(ushort *)((int)__s + 0x50) = param_2[3];
        uVar1 = param_2[2];
        *(undefined1 *)((int)__s + 0x2f) = 0;
        *(undefined1 *)((int)__s + 0x30) = 0;
        *(ushort *)((int)__s + 0x4e) = uVar1;
        *(undefined1 *)((int)__s + 0x31) = 0;
        *(undefined1 *)((int)__s + 0x32) = 0;
        *(undefined1 *)((int)__s + 0x33) = 0;
        iVar7 = (uint)*(byte *)(iVar11 + 0x100) + iVar11;
        for (; iVar7 != iVar11; iVar11 = iVar11 + 1) {
          bVar8 = *(byte *)(iVar11 + 0xdb) >> 3;
          *(byte *)((int)__s + bVar8 + 0x2f) =
               (byte)(1 << (*(byte *)(iVar11 + 0xdb) & 7)) | *(byte *)((int)__s + bVar8 + 0x2f);
        }
        pcVar10 = *(code **)(iVar5 + 0x2c4);
        (*pcVar10)(param_1,pcVar10);
        (**(code **)(_r_modules_funcs_p + 0x1e0))
                  (6,param_1,&bStack_42,abStack_41,*(code **)(_r_modules_funcs_p + 0x1e0));
        uVar13 = (uint)bStack_42;
        uVar15 = (uint)rwip_coex_cfg;
        uVar16 = (uint)abStack_41[0];
        uVar1 = (ushort)rwip_coex_cfg;
        uVar2 = (ushort)rwip_coex_cfg;
        if ((uVar13 << 7 & 0xffffff7f) != 0) {
          (**(code **)(_r_plf_funcs_p + 8))(0,"lld_per_adv.c",0x42,*(code **)(_r_plf_funcs_p + 8));
        }
        if ((uVar16 << 6 & 0xffffffbf) != 0) {
          (**(code **)(_r_plf_funcs_p + 8))(0,"lld_per_adv.c",0x43,*(code **)(_r_plf_funcs_p + 8));
        }
        iVar11 = param_1 * 0x5a;
        iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
        pcVar10 = *(code **)(_r_modules_funcs_p + 0x1a0);
        *(ushort *)(iVar5 + iVar11) =
             (ushort)(uVar13 << 7) | (ushort)(uVar16 << 6) | (uVar2 & 4) << 6 |
             (ushort)((uVar15 & 1) << 10) | (uVar1 & 2) << 8 | 6;
        pbVar6 = (byte *)(*pcVar10)(4,pcVar10);
        if (pbVar6 != (byte *)0x0) {
          bVar8 = pbVar6[1];
          if (0xb < param_1) {
            (**(code **)(_r_plf_funcs_p + 8))
                      (0,"lld_per_adv.c",0x299b,*(code **)(_r_plf_funcs_p + 8));
          }
          if (((uint)bVar8 << 8 & 0xf000) != 0) {
            (**(code **)(_r_plf_funcs_p + 8))
                      (0,"lld_per_adv.c",0x299d,*(code **)(_r_plf_funcs_p + 8));
          }
          puVar14 = (uint *)((param_1 + 0x1800c4cb) * 4);
          *puVar14 = *puVar14 & 0xfffff0ff | (uint)bVar8 << 8;
          bVar8 = *pbVar6;
          if (0xb < param_1) {
            (**(code **)(_r_plf_funcs_p + 8))
                      (0,"lld_per_adv.c",0x294a,*(code **)(_r_plf_funcs_p + 8));
          }
          *puVar14 = (uint)bVar8 << 0x1e | *puVar14 & 0xbfffffff;
          bVar8 = pbVar6[3];
          if (0xb < param_1) {
            (**(code **)(_r_plf_funcs_p + 8))
                      (0,"lld_per_adv.c",0x29bb,*(code **)(_r_plf_funcs_p + 8));
          }
          if ((bVar8 & 0xf0) != 0) {
            (**(code **)(_r_plf_funcs_p + 8))
                      (0,"lld_per_adv.c",0x29bd,*(code **)(_r_plf_funcs_p + 8));
          }
          *puVar14 = *puVar14 & 0xfffffff0 | (uint)bVar8;
          bVar8 = pbVar6[2];
          if (0xb < param_1) {
            (**(code **)(_r_plf_funcs_p + 8))
                      (0,"lld_per_adv.c",0x295a,*(code **)(_r_plf_funcs_p + 8));
          }
          *puVar14 = (uint)bVar8 << 0x1d | *puVar14 & 0xdfffffff;
          bVar8 = pbVar6[7];
          if (0xb < param_1) {
            (**(code **)(_r_plf_funcs_p + 8))
                      (0,"lld_per_adv.c",0x298b,*(code **)(_r_plf_funcs_p + 8));
          }
          if (((uint)bVar8 << 0xc & 0xf0000) != 0) {
            (**(code **)(_r_plf_funcs_p + 8))
                      (0,"lld_per_adv.c",0x298d,*(code **)(_r_plf_funcs_p + 8));
          }
          *puVar14 = *puVar14 & 0xffff0fff | (uint)bVar8 << 0xc;
          bVar8 = pbVar6[8];
          if (0xb < param_1) {
            (**(code **)(_r_plf_funcs_p + 8))
                      (0,"lld_per_adv.c",0x29ab,*(code **)(_r_plf_funcs_p + 8));
          }
          if (((uint)bVar8 << 4 & 0xffffff0f) != 0) {
            (**(code **)(_r_plf_funcs_p + 8))
                      (0,"lld_per_adv.c",0x29ad,*(code **)(_r_plf_funcs_p + 8));
          }
          *puVar14 = *puVar14 & 0xffffff0f | (uint)bVar8 << 4;
          bVar8 = pbVar6[9];
          if (0xb < param_1) {
            (**(code **)(_r_plf_funcs_p + 8))
                      (0,"lld_per_adv.c",0x297b,*(code **)(_r_plf_funcs_p + 8));
          }
          if (((uint)bVar8 << 0x10 & 0xf00000) != 0) {
            (**(code **)(_r_plf_funcs_p + 8))
                      (0,"lld_per_adv.c",0x297d,*(code **)(_r_plf_funcs_p + 8));
          }
          *puVar14 = *puVar14 & 0xfff0ffff | (uint)bVar8 << 0x10;
          uVar1 = *(ushort *)(pbVar6 + 10);
          if (0xb < param_1) {
            (**(code **)(_r_plf_funcs_p + 8))
                      (0,"lld_per_adv.c",0x296a,*(code **)(_r_plf_funcs_p + 8));
          }
          if (((uint)uVar1 << 0x14 & 0xe0000000) != 0) {
            (**(code **)(_r_plf_funcs_p + 8))
                      (0,"lld_per_adv.c",0x296c,*(code **)(_r_plf_funcs_p + 8));
          }
          *puVar14 = *puVar14 & 0xe00fffff | (uint)uVar1 << 0x14;
          bVar8 = pbVar6[6];
          if (0xb < param_1) {
            (**(code **)(_r_plf_funcs_p + 8))
                      (0,"lld_per_adv.c",0x293a,*(code **)(_r_plf_funcs_p + 8));
          }
          *puVar14 = *puVar14 & 0x7fffffff | (uint)bVar8 << 0x1f;
          if (2 < _g_bt_plf_log_level) {
            ets_printf("PTI CNTL CS[%d] REG[%08x] TYPE[PER_ADV] RXEN[%d] RX[%d] IFSEN[%d] IFS[%d] PRTEN[%d] TIME[%d] DIFS[%d] DRX[%d] DTX[%d]\n"
                       ,param_1,puVar14,pbVar6[2],pbVar6[3],*pbVar6,pbVar6[1],pbVar6[6]);
          }
        }
        iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
        *(undefined2 *)(iVar5 + iVar11 + 0x16) = 0xc027;
        if (*(char *)((int)__s + 0x56) != '\x7f') {
          pcVar10 = *(code **)(_r_modules_funcs_p + 0x1fc);
          uVar9 = (*_rwip_rf)(0,_rwip_rf);
          (*pcVar10)(param_1,uVar9);
        }
        iVar7 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
        iVar5 = _r_ip_funcs_p;
        *(undefined2 *)(iVar7 + iVar11 + 0x18) = 0;
        (**(code **)(iVar5 + 0x304))(param_1,6,*(code **)(iVar5 + 0x304));
        uVar3 = *(undefined2 *)((int)__s + 0x2f);
        iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
        *(undefined2 *)(iVar5 + iVar11 + 0x22) = uVar3;
        uVar3 = *(undefined2 *)((int)__s + 0x31);
        iVar7 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
        iVar5 = _r_plf_funcs_p;
        *(undefined2 *)(iVar7 + iVar11 + 0x24) = uVar3;
        bVar8 = *(byte *)((int)__s + 0x33);
        iVar7 = (**(code **)(iVar5 + 0xbc))(0x400,*(code **)(iVar5 + 0xbc));
        iVar5 = _r_ip_funcs_p;
        *(ushort *)(iVar7 + iVar11 + 0x26) = (ushort)bVar8;
        (**(code **)(iVar5 + 0x220))((int)__s + 0x28,param_1,*(code **)(iVar5 + 0x220));
        uVar9 = (**(code **)(_r_osi_funcs_p + 0x88))(*(code **)(_r_osi_funcs_p + 0x88));
        uVar3 = *(undefined2 *)((int)__s + 0x28);
        *(short *)((int)__s + 0x2c) = (short)uVar9;
        iVar5 = _r_plf_funcs_p;
        *(char *)((int)__s + 0x2e) = (char)((uint)uVar9 >> 0x10);
        iVar5 = (**(code **)(iVar5 + 0xbc))(0x400,*(code **)(iVar5 + 0xbc));
        *(undefined2 *)(iVar5 + iVar11 + 0xc) = uVar3;
        uVar3 = *(undefined2 *)((int)__s + 0x2a);
        iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
        *(undefined2 *)(iVar5 + iVar11 + 0xe) = uVar3;
        uVar3 = *(undefined2 *)((int)__s + 0x2c);
        iVar7 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
        iVar5 = _r_plf_funcs_p;
        *(undefined2 *)(iVar7 + iVar11 + 0x10) = uVar3;
        bVar8 = *(byte *)((int)__s + 0x2e);
        iVar5 = (**(code **)(iVar5 + 0xbc))(0x400,*(code **)(iVar5 + 0xbc));
        pcVar10 = *(code **)(_r_plf_funcs_p + 0xbc);
        *(ushort *)(iVar5 + iVar11 + 0x12) = (ushort)bVar8;
        iVar7 = (*pcVar10)(0x400,pcVar10);
        iVar5 = _r_plf_funcs_p;
        *(undefined2 *)(iVar7 + iVar11 + 0x28) = 0;
        iVar7 = (**(code **)(iVar5 + 0xbc))(0x400,*(code **)(iVar5 + 0xbc));
        iVar5 = _r_plf_funcs_p;
        uVar13 = *(uint *)((int)__s + 0x44);
        *(undefined2 *)(iVar7 + iVar11 + 0x2a) = 0;
        iVar5 = (**(code **)(iVar5 + 0xbc))(0x400,*(code **)(iVar5 + 0xbc));
        *(short *)(iVar5 + iVar11 + 0x20) = (short)((uVar13 / 0x271 + 1) * 0x10000 >> 0x10);
        bVar8 = *(byte *)((int)__s + 0x55);
        uVar13 = (uint)bVar8 << 4;
        if ((uVar13 & 0xffffffcf) != 0) {
          (**(code **)(_r_plf_funcs_p + 8))(0,"lld_per_adv.c",0x18e,*(code **)(_r_plf_funcs_p + 8));
        }
        uVar15 = (uint)bVar8 << 2;
        if ((uVar15 & 0xfffffff3) != 0) {
          (**(code **)(_r_plf_funcs_p + 8))(0,"lld_per_adv.c",399,*(code **)(_r_plf_funcs_p + 8));
        }
        if ((bVar8 & 0xfc) != 0) {
          (**(code **)(_r_plf_funcs_p + 8))(0,"lld_per_adv.c",400,*(code **)(_r_plf_funcs_p + 8));
        }
        iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
        *(ushort *)(iVar5 + iVar11 + 4) = (ushort)uVar13 | (ushort)uVar15 | (ushort)bVar8;
        uVar1 = param_2[5];
        if ((param_1 & 0xffffffe0) != 0) {
          (**(code **)(_r_plf_funcs_p + 8))(0,"lld_per_adv.c",0xe6,*(code **)(_r_plf_funcs_p + 8));
        }
        iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
        pcVar10 = *(code **)(_r_ip_funcs_p + 0x264);
        *(ushort *)(iVar11 + 2 + iVar5) = (ushort)(((byte)uVar1 & 1) << 7) | (ushort)param_1 | 0x800
        ;
        iVar5 = (*pcVar10)(pcVar10);
        uVar15 = *(uint *)((int)__s + 0x40);
        uVar13 = rwip_prog_delay + 1 + iVar5 & 0xfffffff;
        if (uVar15 == 0) {
          (**(code **)(_r_plf_funcs_p + 8))(0,"lld_per_adv.c",0x94,*(code **)(_r_plf_funcs_p + 8));
        }
        uVar1 = param_2[4];
        *(undefined4 *)((int)__s + 8) = 0;
        cVar12 = '\x0f';
        *(uint *)((int)__s + 4) = ((uint)uVar1 * 2 + uVar15 + uVar13) - uVar13 % uVar15 & 0xfffffff;
        bVar8 = DAT_0001301b;
        *(ushort *)((int)__s + 0x14) = DAT_0001301b & 0xf | 0x2000;
        do {
          iVar5 = (**(code **)(_r_ip_funcs_p + 0x6b0))(__s,*(code **)(_r_ip_funcs_p + 0x6b0));
          if (iVar5 == 0) {
            *(undefined1 *)((int)__s + 0x53) = 0;
            goto _L317;
          }
          cVar12 = cVar12 + -1;
          *(byte *)((int)__s + 0x16) = *(char *)((int)__s + 0x16) + bVar8;
          *(uint *)((int)__s + 4) = *(int *)((int)__s + 4) + *(int *)((int)__s + 0x40) & 0xfffffff;
        } while (cVar12 != '\0');
        (**(code **)(_r_plf_funcs_p + 8))(0,"lld_per_adv.c",0x57d,*(code **)(_r_plf_funcs_p + 8));
_L317:
        (**(code **)(_r_ip_funcs_p + 0x2d0))(__s,*(code **)(_r_ip_funcs_p + 0x2d0));
        uStack_43 = 0;
      }
    }
    (**(code **)(_r_ip_funcs_p + 0x84c))
              (0,&uStack_43,param_1,param_2,*(code **)(_r_ip_funcs_p + 0x84c));
  }
  return uStack_43;
}

