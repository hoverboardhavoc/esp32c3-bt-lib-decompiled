/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
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
  int iVar3;
  uint uVar4;
  uint *puVar5;
  undefined4 uVar6;
  byte *pbVar7;
  uint uVar8;
  ushort uVar9;
  uint uVar10;
  byte bStack_32;
  byte abStack_31 [5];
  
  iVar3 = *(int *)(&lld_adv_env + param_1 * 4);
  uVar9 = *(ushort *)(iVar3 + 0x74);
  bStack_32 = 0;
  abStack_31[0] = 0;
  if ((uVar9 & 8) == 0) {
    if ((uVar9 & 0x10) == 0) {
      uVar6 = 4;
      uVar9 = 6;
    }
    else {
      uVar6 = 2;
      uVar9 = 4;
    }
  }
  else {
    uVar6 = 3;
    (**(code **)(_r_ip_funcs_p + 0x720))
              (2,param_2 + 0x1000U & 0xfffffff,*(code **)(_r_ip_funcs_p + 0x720));
    uVar9 = 5;
    *(uint *)(iVar3 + 0x10) = (uint)_sch_slice_params;
  }
  (**(code **)(_r_modules_funcs_p + 0x1e0))
            (uVar9,param_1,&bStack_32,abStack_31,*(code **)(_r_modules_funcs_p + 0x1e0));
  uVar8 = (uint)rwip_coex_cfg;
  uVar4 = (uint)bStack_32;
  uVar10 = (uint)abStack_31[0];
  if ((uVar4 << 7 & 0xffffff7f) != 0) {
    (**(code **)(_r_plf_funcs_p + 8))(0,"lld_adv.c",0x42,*(code **)(_r_plf_funcs_p + 8));
  }
  if ((uVar10 << 6 & 0xffffffbf) != 0) {
    (**(code **)(_r_plf_funcs_p + 8))(0,"lld_adv.c",0x43,*(code **)(_r_plf_funcs_p + 8));
  }
  iVar3 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
  *(ushort *)(param_1 * 0x5a + iVar3) =
       (ushort)(uVar4 << 7) | (ushort)(uVar10 << 6) | (ushort)((uVar8 & 1) << 10) |
       (ushort)((uVar8 & 2) << 8) | (ushort)((uVar8 & 4) << 6) | uVar9;
  pbVar7 = (byte *)(**(code **)(_r_modules_funcs_p + 0x1a0))
                             (uVar6,*(code **)(_r_modules_funcs_p + 0x1a0));
  if (pbVar7 != (byte *)0x0) {
    bVar1 = pbVar7[1];
    if (0xb < param_1) {
      (**(code **)(_r_plf_funcs_p + 8))(0,"lld_adv.c",0x299b,*(code **)(_r_plf_funcs_p + 8));
    }
    if (((uint)bVar1 << 8 & 0xf000) != 0) {
      (**(code **)(_r_plf_funcs_p + 8))(0,"lld_adv.c",0x299d,*(code **)(_r_plf_funcs_p + 8));
    }
    puVar5 = (uint *)((param_1 + 0x1800c4cb) * 4);
    *puVar5 = *puVar5 & 0xfffff0ff | (uint)bVar1 << 8;
    bVar1 = *pbVar7;
    if (0xb < param_1) {
      (**(code **)(_r_plf_funcs_p + 8))(0,"lld_adv.c",0x294a,*(code **)(_r_plf_funcs_p + 8));
    }
    *puVar5 = (uint)bVar1 << 0x1e | *puVar5 & 0xbfffffff;
    bVar1 = pbVar7[3];
    if (0xb < param_1) {
      (**(code **)(_r_plf_funcs_p + 8))(0,"lld_adv.c",0x29bb,*(code **)(_r_plf_funcs_p + 8));
    }
    if ((bVar1 & 0xf0) != 0) {
      (**(code **)(_r_plf_funcs_p + 8))(0,"lld_adv.c",0x29bd,*(code **)(_r_plf_funcs_p + 8));
    }
    *puVar5 = *puVar5 & 0xfffffff0 | (uint)bVar1;
    bVar1 = pbVar7[2];
    if (0xb < param_1) {
      (**(code **)(_r_plf_funcs_p + 8))(0,"lld_adv.c",0x295a,*(code **)(_r_plf_funcs_p + 8));
    }
    *puVar5 = (uint)bVar1 << 0x1d | *puVar5 & 0xdfffffff;
    bVar1 = pbVar7[7];
    if (0xb < param_1) {
      (**(code **)(_r_plf_funcs_p + 8))(0,"lld_adv.c",0x298b,*(code **)(_r_plf_funcs_p + 8));
    }
    if (((uint)bVar1 << 0xc & 0xf0000) != 0) {
      (**(code **)(_r_plf_funcs_p + 8))(0,"lld_adv.c",0x298d,*(code **)(_r_plf_funcs_p + 8));
    }
    *puVar5 = *puVar5 & 0xffff0fff | (uint)bVar1 << 0xc;
    bVar1 = pbVar7[8];
    if (0xb < param_1) {
      (**(code **)(_r_plf_funcs_p + 8))(0,"lld_adv.c",0x29ab,*(code **)(_r_plf_funcs_p + 8));
    }
    if (((uint)bVar1 << 4 & 0xffffff0f) != 0) {
      (**(code **)(_r_plf_funcs_p + 8))(0,"lld_adv.c",0x29ad,*(code **)(_r_plf_funcs_p + 8));
    }
    *puVar5 = *puVar5 & 0xffffff0f | (uint)bVar1 << 4;
    bVar1 = pbVar7[9];
    if (0xb < param_1) {
      (**(code **)(_r_plf_funcs_p + 8))(0,"lld_adv.c",0x297b,*(code **)(_r_plf_funcs_p + 8));
    }
    if (((uint)bVar1 << 0x10 & 0xf00000) != 0) {
      (**(code **)(_r_plf_funcs_p + 8))(0,"lld_adv.c",0x297d,*(code **)(_r_plf_funcs_p + 8));
    }
    *puVar5 = *puVar5 & 0xfff0ffff | (uint)bVar1 << 0x10;
    uVar2 = *(ushort *)(pbVar7 + 10);
    if (0xb < param_1) {
      (**(code **)(_r_plf_funcs_p + 8))(0,"lld_adv.c",0x296a,*(code **)(_r_plf_funcs_p + 8));
    }
    if (((uint)uVar2 << 0x14 & 0xe0000000) != 0) {
      (**(code **)(_r_plf_funcs_p + 8))(0,"lld_adv.c",0x296c,*(code **)(_r_plf_funcs_p + 8));
    }
    *puVar5 = *puVar5 & 0xe00fffff | (uint)uVar2 << 0x14;
    bVar1 = pbVar7[6];
    if (0xb < param_1) {
      (**(code **)(_r_plf_funcs_p + 8))(0,"lld_adv.c",0x293a,*(code **)(_r_plf_funcs_p + 8));
    }
    *puVar5 = *puVar5 & 0x7fffffff | (uint)bVar1 << 0x1f;
    if (2 < _g_bt_plf_log_level) {
      ets_printf("PTI CNTL CS[%d] REG[%08x] TYPE[EXT ADV] RXEN[%d] RX[%d], IFSEN[%d] IFS[%d] PRTEN[%d] TIME[%d] DIFS[%d] DRX[%d] DTX[%d]\n"
                 ,param_1,puVar5,pbVar7[2],pbVar7[3],*pbVar7,pbVar7[1],pbVar7[6]);
    }
  }
  return uVar9;
}

