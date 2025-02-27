/*
 * Last changed at upstream commit 0cfafa1e0aa30b7d59f53c38588f0598e228d127
 * https://github.com/espressif/esp32c3-bt-lib/commit/0cfafa1e0aa30b7d59f53c38588f0598e228d127
 * Upstream date: 2025-02-27 20:50:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(b34b7d6)
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
  ushort uVar4;
  ushort uVar5;
  int iVar6;
  int iVar7;
  char *pcVar8;
  undefined1 *puVar9;
  undefined2 *puVar10;
  char cVar11;
  int iVar12;
  uint uVar13;
  
  if (param_1 == 0) goto _L573;
  iVar6 = r_sdk_config_get_opts_ext();
  if (((*(uint *)(iVar6 + 0x28) & 0x20) != 0) &&
     (iVar6 = r_sdk_config_get_opts_ext(), *(byte *)(iVar6 + 0x2c) < 3)) {
    r_ble_log_internal_x2
              (0x40430009,CONCAT11(*(undefined1 *)(param_1 + 0x16),*(undefined1 *)(param_1 + 0x8e)),
               *(undefined4 *)(param_1 + 4));
  }
  iVar6 = (*(byte *)(param_1 + 0x8e) + 0x18) * 2;
  if ((((&DAT_00015061)[iVar6] == '\0') || (*(char *)(param_1 + 0x46) != (&DAT_00015061)[iVar6])) ||
     (uVar13 = (uint)*(ushort *)(param_1 + 0x7c) + (uint)*(ushort *)(param_1 + 0x7e) & 0xffff,
     0x7ffe < (uVar13 - *(ushort *)(param_1 + 0x44) & 0xffff))) goto _L573;
  bVar1 = (&DAT_00015060)[iVar6];
  iVar7 = r_emi_get_mem_addr_by_offset(0x1400);
  iVar12 = (uint)bVar1 * 0xe;
  if (*(short *)(iVar7 + iVar12) < 0) goto _L573;
  iVar7 = r_emi_get_mem_addr_by_offset(0x1400);
  sVar3 = *(short *)(iVar7 + iVar12 + 4);
  iVar7 = r_emi_get_mem_addr_by_offset(0x1400);
  uVar4 = *(ushort *)(iVar12 + 2 + iVar7);
  uVar5 = (ushort)(byte)(&DAT_00015061)[iVar6];
  if (uVar5 == 1) {
    uVar5 = 10;
_L592:
    cVar11 = '\0';
  }
  else if (uVar5 == 2) {
    uVar5 = 6;
    cVar11 = '\x01';
  }
  else {
    cVar11 = '\x18';
    if (uVar5 != 3) {
      r_assert_param(*(undefined1 *)(param_1 + 0x8e),0,"lld_con.c",0x56f);
      uVar5 = 0;
      goto _L592;
    }
  }
  if (((sVar3 == 0) || ((uVar4 & 3) != 3)) ||
     (pcVar8 = (char *)r_emi_get_mem_addr_by_offset(sVar3), *pcVar8 != cVar11)) {
    if (0 < _g_bt_plf_log_level) {
      puVar9 = (undefined1 *)r_emi_get_mem_addr_by_offset(sVar3);
      uVar2 = *puVar9;
      puVar10 = (undefined2 *)r_emi_get_mem_addr_by_offset(sVar3 + uVar5);
      ets_printf("llcp check: %u %u %u %u %u\n",uVar13,uVar2,*puVar10,
                 *(undefined1 *)(param_1 + 0x46),*(undefined2 *)(param_1 + 0x44));
    }
    *(undefined2 *)(&DAT_00015060 + (*(byte *)(param_1 + 0x8e) + 0x18) * 2) = 0;
  }
  else {
    iVar6 = *(ushort *)(param_1 + 0x72) + 9 + uVar13;
    iVar7 = iVar6 * 0x10000;
    puVar9 = (undefined1 *)r_emi_get_mem_addr_by_offset(sVar3 + uVar5);
    *puVar9 = (char)((uint)iVar7 >> 0x10);
    puVar9[1] = (char)((uint)iVar6 >> 8);
    *(short *)(param_1 + 0x44) = (short)((uint)iVar7 >> 0x10);
  }
_L573:
  r_lld_con_evt_start_cbk(param_1);
  iVar6 = r_sdk_config_get_opts_ext();
  if (*(char *)(iVar6 + 0x19) == '\x02') {
    r_lld_cca_con_evt_start_handle(param_1);
  }
  if (con_evt_func_cb == (code *)0x0) {
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x00010016. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*con_evt_func_cb)(*(undefined1 *)(param_1 + 0x8e),1);
  return;
}

