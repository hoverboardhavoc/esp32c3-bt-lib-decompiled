/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> lld_adv.o -> r_lld_adv_start_set_cs
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ushort r_lld_adv_start_set_cs(uint param_1,int param_2)

{
  byte bVar1;
  ushort uVar2;
  byte bVar3;
  byte bVar4;
  byte bVar5;
  int iVar6;
  uint *puVar7;
  undefined4 uVar8;
  byte *pbVar9;
  uint uVar10;
  ushort uVar11;
  byte bStack_32;
  byte abStack_31 [5];
  
  iVar6 = *(int *)(&lld_adv_env + param_1 * 4);
  uVar11 = *(ushort *)(iVar6 + 0x74);
  bStack_32 = 0;
  abStack_31[0] = 0;
  if ((uVar11 & 8) == 0) {
    if ((uVar11 & 0x10) == 0) {
      uVar8 = 4;
      uVar11 = 6;
    }
    else {
      uVar8 = 2;
      uVar11 = 4;
    }
  }
  else {
    uVar8 = 3;
    (**(code **)(_r_ip_funcs_p + 0x720))
              (2,param_2 + 0x1000U & 0xfffffff,*(code **)(_r_ip_funcs_p + 0x720));
    uVar11 = 5;
    *(uint *)(iVar6 + 0x10) = (uint)_sch_slice_params;
  }
  (**(code **)(_r_modules_funcs_p + 0x1e0))
            (uVar11,param_1,&bStack_32,abStack_31,*(code **)(_r_modules_funcs_p + 0x1e0));
  bVar5 = abStack_31[0];
  bVar4 = bStack_32;
  uVar10 = (uint)rwip_coex_cfg;
  bVar1 = rwip_coex_cfg >> 1;
  bVar3 = rwip_coex_cfg >> 2;
  if ((bStack_32 & 0xfe) != 0) {
    (**(code **)(_r_plf_funcs_p + 8))(0,"lld_adv.c",0x42,*(code **)(_r_plf_funcs_p + 8));
  }
  if ((bVar5 & 0xfe) != 0) {
    (**(code **)(_r_plf_funcs_p + 8))(0,"lld_adv.c",0x43,*(code **)(_r_plf_funcs_p + 8));
  }
  iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
  *(ushort *)(param_1 * 0x5a + iVar6) =
       (ushort)bVar4 << 7 | (ushort)bVar5 << 6 | (ushort)((uVar10 & 1) << 10) |
       (ushort)((bVar1 & 1) << 9) | (ushort)((bVar3 & 1) << 8) | uVar11;
  pbVar9 = (byte *)(**(code **)(_r_modules_funcs_p + 0x1a0))
                             (uVar8,*(code **)(_r_modules_funcs_p + 0x1a0));
  if (pbVar9 != (byte *)0x0) {
    bVar1 = pbVar9[1];
    if (0xb < param_1) {
      (**(code **)(_r_plf_funcs_p + 8))(0,"lld_adv.c",0x299b,*(code **)(_r_plf_funcs_p + 8));
    }
    if ((bVar1 & 0xf0) != 0) {
      (**(code **)(_r_plf_funcs_p + 8))(0,"lld_adv.c",0x299d,*(code **)(_r_plf_funcs_p + 8));
    }
    puVar7 = (uint *)((param_1 + 0x1800c4cb) * 4);
    *puVar7 = *puVar7 & 0xfffff0ff | (uint)bVar1 << 8;
    bVar1 = *pbVar9;
    if (0xb < param_1) {
      (**(code **)(_r_plf_funcs_p + 8))(0,"lld_adv.c",0x294a,*(code **)(_r_plf_funcs_p + 8));
    }
    *puVar7 = *puVar7 & 0xbfffffff | (uint)bVar1 << 0x1e;
    bVar1 = pbVar9[3];
    if (0xb < param_1) {
      (**(code **)(_r_plf_funcs_p + 8))(0,"lld_adv.c",0x29bb,*(code **)(_r_plf_funcs_p + 8));
    }
    if (0xf < bVar1) {
      (**(code **)(_r_plf_funcs_p + 8))(0,"lld_adv.c",0x29bd,*(code **)(_r_plf_funcs_p + 8));
    }
    *puVar7 = *puVar7 & 0xfffffff0 | (uint)bVar1;
    bVar1 = pbVar9[2];
    if (0xb < param_1) {
      (**(code **)(_r_plf_funcs_p + 8))(0,"lld_adv.c",0x295a,*(code **)(_r_plf_funcs_p + 8));
    }
    *puVar7 = *puVar7 & 0xdfffffff | (uint)bVar1 << 0x1d;
    bVar1 = pbVar9[7];
    if (0xb < param_1) {
      (**(code **)(_r_plf_funcs_p + 8))(0,"lld_adv.c",0x298b,*(code **)(_r_plf_funcs_p + 8));
    }
    if ((bVar1 & 0xf0) != 0) {
      (**(code **)(_r_plf_funcs_p + 8))(0,"lld_adv.c",0x298d,*(code **)(_r_plf_funcs_p + 8));
    }
    *puVar7 = *puVar7 & 0xffff0fff | (uint)bVar1 << 0xc;
    bVar1 = pbVar9[8];
    if (0xb < param_1) {
      (**(code **)(_r_plf_funcs_p + 8))(0,"lld_adv.c",0x29ab,*(code **)(_r_plf_funcs_p + 8));
    }
    if ((bVar1 & 0xf0) != 0) {
      (**(code **)(_r_plf_funcs_p + 8))(0,"lld_adv.c",0x29ad,*(code **)(_r_plf_funcs_p + 8));
    }
    *puVar7 = *puVar7 & 0xffffff0f | (uint)bVar1 << 4;
    bVar1 = pbVar9[9];
    if (0xb < param_1) {
      (**(code **)(_r_plf_funcs_p + 8))(0,"lld_adv.c",0x297b,*(code **)(_r_plf_funcs_p + 8));
    }
    if ((bVar1 & 0xf0) != 0) {
      (**(code **)(_r_plf_funcs_p + 8))(0,"lld_adv.c",0x297d,*(code **)(_r_plf_funcs_p + 8));
    }
    *puVar7 = *puVar7 & 0xfff0ffff | (uint)bVar1 << 0x10;
    uVar2 = *(ushort *)(pbVar9 + 10);
    if (0xb < param_1) {
      (**(code **)(_r_plf_funcs_p + 8))(0,"lld_adv.c",0x296a,*(code **)(_r_plf_funcs_p + 8));
    }
    if ((uVar2 >> 9 & 7) != 0) {
      (**(code **)(_r_plf_funcs_p + 8))(0,"lld_adv.c",0x296c,*(code **)(_r_plf_funcs_p + 8));
    }
    *puVar7 = *puVar7 & 0xe00fffff | (uint)uVar2 << 0x14;
    bVar1 = pbVar9[6];
    if (0xb < param_1) {
      (**(code **)(_r_plf_funcs_p + 8))(0,"lld_adv.c",0x293a,*(code **)(_r_plf_funcs_p + 8));
    }
    *puVar7 = *puVar7 & 0x7fffffff | (uint)bVar1 << 0x1f;
    if (2 < _g_bt_plf_log_level) {
      ets_printf("PTI CNTL CS[%d] REG[%08x] TYPE[EXT ADV] RXEN[%d] RX[%d], IFSEN[%d] IFS[%d] PRTEN[%d] TIME[%d] DIFS[%d] DRX[%d] DTX[%d]\n"
                 ,param_1,puVar7,pbVar9[2],pbVar9[3],*pbVar9,pbVar9[1],pbVar9[6]);
    }
  }
  return uVar11;
}

