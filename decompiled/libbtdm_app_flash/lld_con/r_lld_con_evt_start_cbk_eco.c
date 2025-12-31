/*
 * Last changed at upstream commit 16cda80aab0a008093592b7e304c77dcb3ac9ea4
 * https://github.com/espressif/esp32c3-bt-lib/commit/16cda80aab0a008093592b7e304c77dcb3ac9ea4
 * Upstream date: 2025-12-31 14:03:52 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(1bb2f50)
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
  undefined1 uVar2;
  short sVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  byte *pbVar8;
  undefined1 *puVar9;
  undefined4 uVar10;
  undefined2 *puVar11;
  int iVar12;
  ushort uVar13;
  uint uVar14;
  uint uVar15;
  
  if (param_1 == 0) goto _L521;
  r_ble_log_internal_x2
            (0x404300e0,*(undefined4 *)(param_1 + 4),
             CONCAT11(*(undefined1 *)(param_1 + 0x16),*(undefined1 *)(param_1 + 0x8e)));
  iVar12 = (*(byte *)(param_1 + 0x8e) + 0x18) * 2;
  if (((&DAT_0001507d)[iVar12] == '\0') || (*(char *)(param_1 + 0x46) != (&DAT_0001507d)[iVar12]))
  goto _L521;
  uVar14 = (uint)*(ushort *)(param_1 + 0x7c) + (uint)*(ushort *)(param_1 + 0x7e) & 0xffff;
  bVar1 = (&DAT_0001507c)[iVar12];
  if (0x7ffe < (uVar14 - *(ushort *)(param_1 + 0x44) & 0xffff)) goto _L521;
  iVar4 = (uint)bVar1 * 0xe;
  iVar7 = r_emi_get_mem_addr_by_offset(0x1400);
  if (*(short *)(iVar7 + iVar4) < 0) goto _L521;
  iVar7 = r_emi_get_mem_addr_by_offset(0x1400);
  sVar3 = *(short *)(iVar4 + 4 + iVar7);
  iVar7 = r_emi_get_mem_addr_by_offset(0x1400);
  uVar13 = (ushort)(byte)(&DAT_0001507d)[iVar12];
  uVar5 = *(ushort *)(iVar4 + 2 + iVar7) & 3;
  if (uVar13 == 1) {
    uVar13 = 10;
_L537:
    uVar15 = 0;
  }
  else if (uVar13 == 2) {
    uVar13 = 6;
    uVar15 = 1;
  }
  else {
    uVar15 = 0x18;
    if (uVar13 != 3) {
      r_assert_param(*(undefined1 *)(param_1 + 0x8e),0,"lld_con.c",0x5a6);
      uVar13 = 0;
      goto _L537;
    }
  }
  if (((sVar3 == 0) || (uVar5 != 3)) ||
     (pbVar8 = (byte *)r_emi_get_mem_addr_by_offset(sVar3), *pbVar8 != uVar15)) {
    if (0 < _g_bt_plf_log_level) {
      puVar9 = (undefined1 *)r_emi_get_mem_addr_by_offset(sVar3);
      uVar2 = *puVar9;
      puVar11 = (undefined2 *)r_emi_get_mem_addr_by_offset(sVar3 + uVar13);
      ets_printf("llcp check: %u %u %u %u %u\n",uVar14,uVar2,*puVar11,
                 *(undefined1 *)(param_1 + 0x46),*(undefined2 *)(param_1 + 0x44));
    }
    bVar1 = *(byte *)(param_1 + 0x8e);
    r_lld_con_llcp_ind_info_clear((uint)bVar1);
    uVar6 = (uint)*(ushort *)(param_1 + 0x44);
    uVar5 = (uint)*(byte *)(param_1 + 0x46) << 0x18 | (uint)bVar1 | uVar5 << 8;
    uVar10 = 0x80a300e2;
  }
  else {
    uVar6 = *(ushort *)(param_1 + 0x72) + 9 + uVar14;
    iVar12 = uVar6 * 0x10000;
    puVar9 = (undefined1 *)r_emi_get_mem_addr_by_offset(sVar3 + uVar13);
    uVar6 = uVar6 & 0xffff;
    *puVar9 = (char)((uint)iVar12 >> 0x10);
    puVar9[1] = (char)(uVar6 >> 8);
    uVar5 = (uint)CONCAT11(bVar1,*(undefined1 *)(param_1 + 0x8e));
    *(short *)(param_1 + 0x44) = (short)((uint)iVar12 >> 0x10);
    uVar10 = 0x40a300e1;
  }
  r_ble_log_internal_x2(uVar10,uVar6 << 0x10 | uVar14,uVar5 | uVar15 << 0x10);
_L521:
  r_lld_con_evt_start_cbk(param_1);
  iVar12 = r_sdk_config_get_opts_ext();
  if (*(char *)(iVar12 + 0x19) == '\x02') {
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

