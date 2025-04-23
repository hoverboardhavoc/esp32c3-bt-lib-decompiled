/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
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
  byte bVar3;
  byte bVar4;
  byte bVar5;
  int iVar6;
  void *__s;
  byte *pbVar7;
  int iVar8;
  byte bVar9;
  undefined4 uVar10;
  code *pcVar11;
  char cVar12;
  int iVar13;
  uint *puVar14;
  uint uVar15;
  uint uVar16;
  undefined1 uStack_43;
  byte bStack_42;
  byte abStack_41 [13];
  
  uStack_43 = 0xc;
  iVar6 = (**(code **)(_r_ip_funcs_p + 0x84c))
                    (1,&uStack_43,param_1,param_2,*(code **)(_r_ip_funcs_p + 0x84c));
  if (iVar6 != 0) {
    return uStack_43;
  }
  if (*(int *)(&lld_per_adv_env + param_1 * 4) != 0) goto _L258;
  __s = (void *)(**(code **)(_r_modules_funcs_p + 0x120))
                          (0x60,0,*(code **)(_r_modules_funcs_p + 0x120));
  *(void **)(&lld_per_adv_env + param_1 * 4) = __s;
  if (__s == (void *)0x0) {
    (**(code **)(_r_plf_funcs_p + 8))(0x10000,0x587,*(code **)(_r_plf_funcs_p + 8));
    goto _L258;
  }
  bStack_42 = 0;
  abStack_41[0] = 0;
  memset(__s,0,0x60);
  iVar6 = _r_ip_funcs_p;
  *(undefined4 *)((int)__s + 0x20) = *(undefined4 *)(_r_ip_funcs_p + 0x2e0);
  uVar10 = *(undefined4 *)(iVar6 + 0x2e4);
  *(char *)((int)__s + 0x52) = (char)param_1;
  *(undefined4 *)((int)__s + 0x18) = uVar10;
  *(undefined1 *)((int)__s + 0x16) = DAT_0001301a;
  *(ushort *)((int)__s + 0x48) = param_2[1];
  *(uint *)((int)__s + 0x40) = (uint)*param_2 << 2;
  *(undefined2 *)((int)__s + 0x3a) = 10;
  *(char *)((int)__s + 0x54) = (char)param_2[5];
  *(undefined1 *)((int)__s + 0x56) = *(undefined1 *)((int)param_2 + 0xb);
  iVar13 = _p_lld_env;
  bVar9 = (byte)param_2[6];
  if ((bVar9 < 3) || (*(char *)(_p_lld_env + 0xda) == '\0')) {
    bVar9 = bVar9 - 1;
  }
  *(byte *)((int)__s + 0x55) = bVar9;
  *(ushort *)((int)__s + 0x50) = param_2[3];
  uVar1 = param_2[2];
  *(undefined1 *)((int)__s + 0x2f) = 0;
  *(undefined1 *)((int)__s + 0x30) = 0;
  *(ushort *)((int)__s + 0x4e) = uVar1;
  *(undefined1 *)((int)__s + 0x31) = 0;
  *(undefined1 *)((int)__s + 0x32) = 0;
  *(undefined1 *)((int)__s + 0x33) = 0;
  iVar8 = (uint)*(byte *)(iVar13 + 0x100) + iVar13;
  for (; iVar13 != iVar8; iVar13 = iVar13 + 1) {
    bVar9 = *(byte *)(iVar13 + 0xdb) >> 3;
    *(byte *)((int)__s + bVar9 + 0x2f) =
         (byte)(1 << (*(byte *)(iVar13 + 0xdb) & 7)) | *(byte *)((int)__s + bVar9 + 0x2f);
  }
  pcVar11 = *(code **)(iVar6 + 0x2c4);
  (*pcVar11)(param_1,pcVar11);
  (**(code **)(_r_modules_funcs_p + 0x1e0))
            (6,param_1,&bStack_42,abStack_41,*(code **)(_r_modules_funcs_p + 0x1e0));
  bVar5 = abStack_41[0];
  bVar4 = bStack_42;
  uVar16 = (uint)rwip_coex_cfg;
  bVar9 = rwip_coex_cfg >> 1;
  bVar3 = rwip_coex_cfg >> 2;
  if ((bStack_42 & 0xfe) != 0) {
    (**(code **)(_r_plf_funcs_p + 8))(0,0x10000,0x42,*(code **)(_r_plf_funcs_p + 8));
  }
  if ((bVar5 & 0xfe) != 0) {
    (**(code **)(_r_plf_funcs_p + 8))(0,0x10000,0x43,*(code **)(_r_plf_funcs_p + 8));
  }
  iVar13 = param_1 * 0x5a;
  iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
  *(ushort *)(iVar6 + iVar13) =
       (ushort)bVar4 << 7 | (ushort)bVar5 << 6 | (ushort)((bVar3 & 1) << 8) |
       (ushort)((uVar16 & 1) << 10) | (ushort)((bVar9 & 1) << 9) | 6;
  pbVar7 = (byte *)(**(code **)(_r_modules_funcs_p + 0x1a0))
                             (4,*(code **)(_r_modules_funcs_p + 0x1a0));
  if (pbVar7 != (byte *)0x0) {
    bVar9 = pbVar7[1];
    if (0xb < param_1) {
      (**(code **)(_r_plf_funcs_p + 8))(0,0x10000,0x299b,*(code **)(_r_plf_funcs_p + 8));
    }
    if ((bVar9 & 0xf0) != 0) {
      (**(code **)(_r_plf_funcs_p + 8))(0,0x10000,0x299d,*(code **)(_r_plf_funcs_p + 8));
    }
    puVar14 = (uint *)((param_1 + 0x1800c4cb) * 4);
    *puVar14 = *puVar14 & 0xfffff0ff | (uint)bVar9 << 8;
    bVar9 = *pbVar7;
    if (0xb < param_1) {
      (**(code **)(_r_plf_funcs_p + 8))(0,0x10000,0x294a,*(code **)(_r_plf_funcs_p + 8));
    }
    *puVar14 = *puVar14 & 0xbfffffff | (uint)bVar9 << 0x1e;
    bVar9 = pbVar7[3];
    if (0xb < param_1) {
      (**(code **)(_r_plf_funcs_p + 8))(0,0x10000,0x29bb,*(code **)(_r_plf_funcs_p + 8));
    }
    if (0xf < bVar9) {
      (**(code **)(_r_plf_funcs_p + 8))(0,0x10000,0x29bd,*(code **)(_r_plf_funcs_p + 8));
    }
    *puVar14 = *puVar14 & 0xfffffff0 | (uint)bVar9;
    bVar9 = pbVar7[2];
    if (0xb < param_1) {
      (**(code **)(_r_plf_funcs_p + 8))(0,0x10000,0x295a,*(code **)(_r_plf_funcs_p + 8));
    }
    *puVar14 = *puVar14 & 0xdfffffff | (uint)bVar9 << 0x1d;
    bVar9 = pbVar7[7];
    if (0xb < param_1) {
      (**(code **)(_r_plf_funcs_p + 8))(0,0x10000,0x298b,*(code **)(_r_plf_funcs_p + 8));
    }
    if ((bVar9 & 0xf0) != 0) {
      (**(code **)(_r_plf_funcs_p + 8))(0,0x10000,0x298d,*(code **)(_r_plf_funcs_p + 8));
    }
    *puVar14 = *puVar14 & 0xffff0fff | (uint)bVar9 << 0xc;
    bVar9 = pbVar7[8];
    if (0xb < param_1) {
      (**(code **)(_r_plf_funcs_p + 8))(0,0x10000,0x29ab,*(code **)(_r_plf_funcs_p + 8));
    }
    if ((bVar9 & 0xf0) != 0) {
      (**(code **)(_r_plf_funcs_p + 8))(0,0x10000,0x29ad,*(code **)(_r_plf_funcs_p + 8));
    }
    *puVar14 = *puVar14 & 0xffffff0f | (uint)bVar9 << 4;
    bVar9 = pbVar7[9];
    if (0xb < param_1) {
      (**(code **)(_r_plf_funcs_p + 8))(0,0x10000,0x297b,*(code **)(_r_plf_funcs_p + 8));
    }
    if ((bVar9 & 0xf0) != 0) {
      (**(code **)(_r_plf_funcs_p + 8))(0,0x10000,0x297d,*(code **)(_r_plf_funcs_p + 8));
    }
    *puVar14 = *puVar14 & 0xfff0ffff | (uint)bVar9 << 0x10;
    uVar1 = *(ushort *)(pbVar7 + 10);
    if (0xb < param_1) {
      (**(code **)(_r_plf_funcs_p + 8))(0,0x10000,0x296a,*(code **)(_r_plf_funcs_p + 8));
    }
    if ((uVar1 >> 9 & 7) != 0) {
      (**(code **)(_r_plf_funcs_p + 8))(0,0x10000,0x296c,*(code **)(_r_plf_funcs_p + 8));
    }
    *puVar14 = *puVar14 & 0xe00fffff | (uint)uVar1 << 0x14;
    bVar9 = pbVar7[6];
    if (0xb < param_1) {
      (**(code **)(_r_plf_funcs_p + 8))(0,0x10000,0x293a,*(code **)(_r_plf_funcs_p + 8));
    }
    *puVar14 = *puVar14 & 0x7fffffff | (uint)bVar9 << 0x1f;
    if (2 < _g_bt_plf_log_level) {
      ets_printf("PTI CNTL CS[%d] REG[%08x] TYPE[PER_ADV] RXEN[%d] RX[%d] IFSEN[%d] IFS[%d] PRTEN[%d] TIME[%d] DIFS[%d] DRX[%d] DTX[%d]\n"
                 ,param_1,puVar14,pbVar7[2],pbVar7[3],*pbVar7,pbVar7[1],pbVar7[6]);
    }
  }
  iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
  *(undefined2 *)(iVar13 + 0x16 + iVar6) = 0xc027;
  if (*(char *)((int)__s + 0x56) != '\x7f') {
    pcVar11 = *(code **)(_r_modules_funcs_p + 0x1fc);
    uVar10 = (*_memset)(0,_memset);
    (*pcVar11)(param_1,uVar10);
  }
  iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
  *(undefined2 *)(iVar13 + 0x18 + iVar6) = 0;
  (**(code **)(_r_ip_funcs_p + 0x304))(param_1,6,*(code **)(_r_ip_funcs_p + 0x304));
  uVar2 = *(undefined2 *)((int)__s + 0x2f);
  iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
  *(undefined2 *)(iVar13 + 0x22 + iVar6) = uVar2;
  uVar2 = *(undefined2 *)((int)__s + 0x31);
  iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
  *(undefined2 *)(iVar13 + 0x24 + iVar6) = uVar2;
  bVar9 = *(byte *)((int)__s + 0x33);
  iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
  *(ushort *)(iVar13 + 0x26 + iVar6) = (ushort)bVar9;
  (**(code **)(_r_ip_funcs_p + 0x220))((int)__s + 0x28,param_1,*(code **)(_r_ip_funcs_p + 0x220));
  uVar10 = (**(code **)(_r_osi_funcs_p + 0x88))(*(code **)(_r_osi_funcs_p + 0x88));
  iVar6 = _r_plf_funcs_p;
  *(short *)((int)__s + 0x2c) = (short)uVar10;
  *(char *)((int)__s + 0x2e) = (char)((uint)uVar10 >> 0x10);
  uVar2 = *(undefined2 *)((int)__s + 0x28);
  iVar6 = (**(code **)(iVar6 + 0xbc))(0x400,*(code **)(iVar6 + 0xbc));
  *(undefined2 *)(iVar13 + 0xc + iVar6) = uVar2;
  uVar2 = *(undefined2 *)((int)__s + 0x2a);
  iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
  *(undefined2 *)(iVar13 + 0xe + iVar6) = uVar2;
  uVar2 = *(undefined2 *)((int)__s + 0x2c);
  iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
  *(undefined2 *)(iVar13 + 0x10 + iVar6) = uVar2;
  bVar9 = *(byte *)((int)__s + 0x2e);
  iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
  *(ushort *)(iVar13 + 0x12 + iVar6) = (ushort)bVar9;
  iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
  *(undefined2 *)(iVar13 + 0x28 + iVar6) = 0;
  iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
  uVar16 = *(uint *)((int)__s + 0x44);
  *(undefined2 *)(iVar13 + 0x2a + iVar6) = 0;
  iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
  *(short *)(iVar13 + 0x20 + iVar6) = (short)((uVar16 / 0x271 + 1) * 0x10000 >> 0x10);
  bVar9 = *(byte *)((int)__s + 0x55);
  if ((bVar9 & 0xfc) == 0) {
    if (3 < bVar9) goto _L286;
  }
  else {
    (**(code **)(_r_plf_funcs_p + 8))(0,0x10000,0x18e,*(code **)(_r_plf_funcs_p + 8));
    (**(code **)(_r_plf_funcs_p + 8))(0,0x10000,399,*(code **)(_r_plf_funcs_p + 8));
_L286:
    (**(code **)(_r_plf_funcs_p + 8))(0,0x10000,400,*(code **)(_r_plf_funcs_p + 8));
  }
  iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
  *(ushort *)(iVar13 + 4 + iVar6) = (ushort)bVar9 | (ushort)bVar9 << 4 | (ushort)bVar9 << 2;
  uVar1 = param_2[5];
  if (0x1f < param_1) {
    (**(code **)(_r_plf_funcs_p + 8))(0,0x10000,0xe6,*(code **)(_r_plf_funcs_p + 8));
  }
  iVar8 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
  iVar6 = _r_ip_funcs_p;
  *(ushort *)(iVar13 + 2 + iVar8) = (ushort)(((byte)uVar1 & 1) << 7) | (ushort)param_1 | 0x800;
  iVar6 = (**(code **)(iVar6 + 0x264))(*(code **)(iVar6 + 0x264));
  uVar15 = *(uint *)((int)__s + 0x40);
  uVar16 = rwip_prog_delay + 1 + iVar6 & 0xfffffff;
  if (uVar15 == 0) {
    (**(code **)(_r_plf_funcs_p + 8))(0,0x10000,0x94,*(code **)(_r_plf_funcs_p + 8));
  }
  uVar1 = param_2[4];
  *(undefined4 *)((int)__s + 8) = 0;
  *(uint *)((int)__s + 4) = ((uint)uVar1 * 2 + uVar15 + uVar16) - uVar16 % uVar15 & 0xfffffff;
  bVar9 = DAT_0001301b;
  cVar12 = '\x0f';
  *(ushort *)((int)__s + 0x14) = DAT_0001301b & 0xf | 0x2000;
  do {
    iVar6 = (**(code **)(_r_ip_funcs_p + 0x6b0))(__s,*(code **)(_r_ip_funcs_p + 0x6b0));
    if (iVar6 == 0) {
      *(undefined1 *)((int)__s + 0x53) = 0;
      goto _L293;
    }
    cVar12 = cVar12 + -1;
    *(byte *)((int)__s + 0x16) = *(char *)((int)__s + 0x16) + bVar9;
    *(uint *)((int)__s + 4) = *(int *)((int)__s + 4) + *(int *)((int)__s + 0x40) & 0xfffffff;
  } while (cVar12 != '\0');
  (**(code **)(_r_plf_funcs_p + 8))(0,0x10000,0x57d,*(code **)(_r_plf_funcs_p + 8));
_L293:
  (**(code **)(_r_ip_funcs_p + 0x2d0))(__s,*(code **)(_r_ip_funcs_p + 0x2d0));
  uStack_43 = 0;
_L258:
  (**(code **)(_r_ip_funcs_p + 0x84c))
            (0,&uStack_43,param_1,param_2,*(code **)(_r_ip_funcs_p + 0x84c));
  return uStack_43;
}

