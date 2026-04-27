/*
 * Last changed at upstream commit 58d499bba1019a80a622df60aa38f59c1e4565ba
 * https://github.com/espressif/esp32c3-bt-lib/commit/58d499bba1019a80a622df60aa38f59c1e4565ba
 * Upstream date: 2026-04-27 15:45:42 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(2f683593)
 * Source: libbtdm_app_flash -> lld_con.o -> r_lld_con_evt_start_cbk_eco
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_con_evt_start_cbk_eco(int param_1)

{
  byte bVar1;
  byte bVar2;
  undefined1 uVar3;
  ushort uVar4;
  short sVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  byte *pbVar9;
  undefined1 *puVar10;
  undefined2 *puVar11;
  undefined4 uVar12;
  ushort uVar13;
  uint uVar14;
  int iVar15;
  int iVar16;
  uint uVar17;
  
  if (param_1 == 0) goto _L554;
  if (*(short *)(param_1 + 0x84) < 0) {
    uVar14 = (uint)*(byte *)(param_1 + 0x8e);
    iVar15 = uVar14 * 4;
    if (-1 < (char)lld_con_fake_rx[iVar15 + 2]) {
      iVar8 = r_emi_get_mem_addr_by_offset(0x400);
      iVar16 = uVar14 * 0x5a + 0x18;
      uVar13 = *(ushort *)(iVar8 + iVar16);
      iVar8 = r_emi_get_mem_addr_by_offset(0x400);
      uVar4 = *(ushort *)(iVar8 + iVar16);
      iVar8 = r_emi_get_mem_addr_by_offset(0x400);
      *(ushort *)(iVar8 + iVar16) =
           (ushort)((~((int)(uint)uVar13 >> 0xd) & 1U) << 0xd) | uVar4 & 0xdfff;
      bVar1 = *(byte *)(param_1 + 0x8e);
      bVar2 = *(byte *)(param_1 + 0x90);
      iVar8 = r_emi_get_mem_addr_by_offset(0x400);
      *(ushort *)(uVar14 * 0x5a + 0x1c + iVar8) =
           ((ushort)bVar1 * 9 + (ushort)bVar2 & 0xff) * 0xe + 0x1400;
    }
    if ((lld_con_fake_rx[iVar15 + 2] & 0x40) == 0) {
      iVar8 = r_emi_get_mem_addr_by_offset(0x400);
      iVar16 = uVar14 * 0x5a + 0x18;
      uVar13 = *(ushort *)(iVar8 + iVar16);
      iVar8 = r_emi_get_mem_addr_by_offset(0x400);
      uVar4 = *(ushort *)(iVar8 + iVar16);
      iVar8 = r_emi_get_mem_addr_by_offset(0x400);
      *(ushort *)(iVar8 + iVar16) =
           (ushort)((~((int)(uint)uVar13 >> 0xc) & 1U) << 0xc) | uVar4 & 0xefff;
    }
    if ((*(ushort *)(param_1 + 0x84) >> 0xb & 1) == 0) {
      if (-1 < (char)lld_con_fake_rx[iVar15 + 2]) {
        iVar8 = r_emi_get_mem_addr_by_offset(0x400);
        iVar16 = uVar14 * 0x5a + 0x18;
        uVar13 = *(ushort *)(iVar8 + iVar16);
        iVar8 = r_emi_get_mem_addr_by_offset(0x400);
        *(ushort *)(iVar8 + iVar16) = uVar13 & 0xbfff | 0x4000;
      }
    }
    else {
      iVar16 = r_emi_get_mem_addr_by_offset(0x400);
      iVar8 = uVar14 * 0x5a + 0x18;
      uVar13 = *(ushort *)(iVar16 + iVar8);
      iVar16 = r_emi_get_mem_addr_by_offset(0x400);
      *(ushort *)(iVar16 + iVar8) = uVar13 & 0xbfff;
    }
    bVar1 = lld_con_fake_rx[iVar15 + 2];
    r_ble_log_internal_x4
              (0x40c30103,bVar1 >> 7,bVar1 >> 6 & 1,
               (int)(uint)*(ushort *)(param_1 + 0x84) >> 0xb & 1,
               CONCAT11(bVar1,*(undefined1 *)(param_1 + 0x8e)));
    *(ushort *)(param_1 + 0x84) = *(ushort *)(param_1 + 0x84) & 0x77ff;
  }
  bVar1 = *(byte *)(param_1 + 0x8e);
  uVar12 = *(undefined4 *)(param_1 + 4);
  iVar15 = r_emi_get_mem_addr_by_offset(0x400);
  r_ble_log_internal_x3
            (0x40430104,uVar12,
             *(int *)(param_1 + 8) << 0x10 | *(ushort *)((uint)bVar1 * 0x5a + iVar15) & 0x1f);
  iVar15 = (*(byte *)(param_1 + 0x8e) + 0x18) * 2;
  if (((&DAT_00015651)[iVar15] == '\0') || (*(char *)(param_1 + 0x46) != (&DAT_00015651)[iVar15]))
  goto _L554;
  uVar14 = (uint)*(ushort *)(param_1 + 0x7c) + (uint)*(ushort *)(param_1 + 0x7e) & 0xffff;
  bVar1 = (&DAT_00015650)[iVar15];
  if (0x7ffe < ((uVar14 - *(ushort *)(param_1 + 0x44)) + 1 & 0xffff)) goto _L554;
  iVar8 = (uint)bVar1 * 0xe;
  iVar16 = r_emi_get_mem_addr_by_offset(0x1400);
  if (*(short *)(iVar16 + iVar8) < 0) goto _L554;
  iVar16 = r_emi_get_mem_addr_by_offset(0x1400);
  sVar5 = *(short *)(iVar8 + 4 + iVar16);
  iVar16 = r_emi_get_mem_addr_by_offset(0x1400);
  uVar13 = (ushort)(byte)(&DAT_00015651)[iVar15];
  uVar6 = *(ushort *)(iVar8 + 2 + iVar16) & 3;
  if (uVar13 == 1) {
    uVar13 = 10;
_L575:
    uVar17 = 0;
  }
  else if (uVar13 == 2) {
    uVar13 = 6;
    uVar17 = 1;
  }
  else {
    uVar17 = 0x18;
    if (uVar13 != 3) {
      r_assert_param(*(undefined1 *)(param_1 + 0x8e),0,"lld_con.c",0x63d);
      uVar13 = 0;
      goto _L575;
    }
  }
  if (((sVar5 == 0) || (uVar6 != 3)) ||
     (pbVar9 = (byte *)r_emi_get_mem_addr_by_offset(sVar5), *pbVar9 != uVar17)) {
    if (0 < _g_bt_plf_log_level) {
      puVar10 = (undefined1 *)r_emi_get_mem_addr_by_offset(sVar5);
      uVar3 = *puVar10;
      puVar11 = (undefined2 *)r_emi_get_mem_addr_by_offset(sVar5 + uVar13);
      ets_printf("llcp check: %u %u %u %u %u\n",uVar14,uVar3,*puVar11,
                 *(undefined1 *)(param_1 + 0x46),*(undefined2 *)(param_1 + 0x44));
    }
    bVar1 = *(byte *)(param_1 + 0x8e);
    r_lld_con_llcp_ind_info_clear((uint)bVar1);
    uVar7 = (uint)*(ushort *)(param_1 + 0x44);
    uVar6 = (uint)*(byte *)(param_1 + 0x46) << 0x18 | (uint)bVar1 | uVar6 << 8;
    uVar12 = 0x80a30106;
  }
  else {
    uVar7 = *(ushort *)(param_1 + 0x72) + 9 + uVar14;
    iVar15 = uVar7 * 0x10000;
    puVar10 = (undefined1 *)r_emi_get_mem_addr_by_offset(sVar5 + uVar13);
    uVar7 = uVar7 & 0xffff;
    *puVar10 = (char)((uint)iVar15 >> 0x10);
    puVar10[1] = (char)(uVar7 >> 8);
    uVar6 = (uint)CONCAT11(bVar1,*(undefined1 *)(param_1 + 0x8e));
    *(short *)(param_1 + 0x44) = (short)((uint)iVar15 >> 0x10);
    uVar12 = 0x40a30105;
  }
  r_ble_log_internal_x2(uVar12,uVar7 << 0x10 | uVar14,uVar6 | uVar17 << 0x10);
_L554:
  r_lld_con_evt_start_cbk(param_1);
  iVar15 = r_sdk_config_get_opts_ext();
  if (*(char *)(iVar15 + 0x19) == '\x02') {
    r_lld_cca_con_evt_start_handle(param_1);
  }
  if (con_evt_func_cb == (code *)0x0) {
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x00010014. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*con_evt_func_cb)(*(undefined1 *)(param_1 + 0x8e),1);
  return;
}

