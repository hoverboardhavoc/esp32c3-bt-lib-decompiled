/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> lld_con.o -> r_lld_con_tx_prog_new_packet_coex
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_con_tx_prog_new_packet_coex(int param_1)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  byte bVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  code *pcVar10;
  ushort uVar11;
  uint uVar12;
  byte bStack_42;
  byte abStack_41 [13];
  
  uVar9 = (uint)*(byte *)(param_1 + 0x8e);
  bVar1 = *(byte *)(param_1 + 0x91);
  if (*(char *)(param_1 + 0x92) == '\0') {
    bStack_42 = 0;
    abStack_41[0] = 0;
    iVar7 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
    uVar11 = *(ushort *)(iVar7 + uVar9 * 0x5a) & 0x1f;
    (**(code **)(_r_modules_funcs_p + 0x1e0))
              (uVar11,uVar9,&bStack_42,abStack_41,*(code **)(_r_modules_funcs_p + 0x1e0));
    bVar5 = abStack_41[0];
    bVar4 = bStack_42;
    uVar12 = (uint)rwip_coex_cfg;
    bVar2 = rwip_coex_cfg >> 1;
    bVar3 = rwip_coex_cfg >> 2;
    if ((bStack_42 & 0xfe) != 0) {
      (**(code **)(_r_plf_funcs_p + 8))(0,"lld_con.c",0x42,*(code **)(_r_plf_funcs_p + 8));
    }
    if ((bVar5 & 0xfe) != 0) {
      (**(code **)(_r_plf_funcs_p + 8))(0,"lld_con.c",0x43,*(code **)(_r_plf_funcs_p + 8));
    }
    iVar7 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
    *(ushort *)(iVar7 + uVar9 * 0x5a) =
         (ushort)bVar4 << 7 | (ushort)bVar5 << 6 | (ushort)((uVar12 & 1) << 10) |
         (ushort)((bVar2 & 1) << 9) | (ushort)((bVar3 & 1) << 8) | uVar11;
  }
  bVar2 = *(byte *)(param_1 + 0x8e);
  pcVar10 = *(code **)(_r_modules_funcs_p + 0x1a0);
  iVar7 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
  iVar7 = (*pcVar10)((*(ushort *)((uint)bVar2 * 0x5a + iVar7) & 0x1f) != 2);
  if (iVar7 != 0) {
    if (2 < _g_bt_plf_log_level) {
      ets_printf("TX PTI [CON] [EN%d] [%d] \n",*(undefined1 *)(iVar7 + 4),*(undefined1 *)(iVar7 + 5)
                );
    }
    bVar2 = *(byte *)(iVar7 + 5);
    if ((bVar2 & 0xf0) != 0) {
      (**(code **)(_r_plf_funcs_p + 8))(0,"lld_con.c",0x33f,*(code **)(_r_plf_funcs_p + 8));
    }
    iVar8 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
    iVar6 = ((uint)bVar1 + uVar9 * 9 & 0xff) * 0xe + 10;
    uVar11 = *(ushort *)(iVar8 + iVar6);
    iVar8 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
    pcVar10 = *(code **)(_r_plf_funcs_p + 0xbc);
    *(ushort *)(iVar8 + iVar6) = uVar11 & 0xf0ff | (ushort)bVar2 << 8;
    bVar1 = *(byte *)(iVar7 + 4);
    iVar7 = (*pcVar10)(0x1400,pcVar10);
    uVar11 = *(ushort *)(iVar7 + iVar6);
    iVar7 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
    *(ushort *)(iVar7 + iVar6) = uVar11 & 0xefff | (ushort)bVar1 << 0xc;
  }
  return;
}

