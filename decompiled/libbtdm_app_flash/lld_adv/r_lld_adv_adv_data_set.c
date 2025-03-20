/*
 * Last changed at upstream commit aaf54a5f7e122db70b4a7ff02d2617858d43f649
 * https://github.com/espressif/esp32c3-bt-lib/commit/aaf54a5f7e122db70b4a7ff02d2617858d43f649
 * Upstream date: 2025-03-20 20:31:24 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(d74042a8)
 * Source: libbtdm_app_flash -> lld_adv.o -> r_lld_adv_adv_data_set
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_adv_adv_data_set(int param_1,int param_2,undefined2 param_3,int param_4,int param_5)

{
  undefined1 uVar1;
  undefined1 uVar2;
  byte bVar3;
  uint uVar4;
  int iVar5;
  ushort uVar6;
  int iVar7;
  char *pcVar8;
  short sVar9;
  int iVar10;
  
  iVar10 = *(int *)(&lld_adv_env + param_1 * 4);
  uVar4 = param_1 * 9 & 0xff;
  if ((*(ushort *)(iVar10 + 0x74) & 0x10) == 0) {
    sVar9 = 0;
    uVar6 = (**(code **)(_r_osi_funcs_p + 0x88))(*(code **)(_r_osi_funcs_p + 0x88));
    *(ushort *)(iVar10 + 0x76) = *(ushort *)(iVar10 + 0x76) & 0xf000 | uVar6 & 0xfff;
    if (param_4 != 0) {
      iVar5 = r_emi_get_mem_addr_by_offset(0x1400);
      sVar9 = *(short *)(iVar5 + (uVar4 + 1 & 0xff) * 0xe + 4);
    }
    *(short *)(iVar10 + 0x82) = (short)param_2;
    *(undefined2 *)(iVar10 + 0x7e) = param_3;
    r_lld_adv_ext_chain_construct(*(undefined1 *)(iVar10 + 0x87));
    goto _L633;
  }
  iVar5 = uVar4 * 0xe;
  sVar9 = 0;
  if (param_4 != 0) {
    iVar7 = r_emi_get_mem_addr_by_offset(0x1400);
    sVar9 = *(short *)(iVar7 + iVar5 + 4);
  }
  iVar7 = r_emi_get_mem_addr_by_offset(0x1400);
  uVar6 = *(ushort *)(iVar7 + iVar5 + 2);
  iVar7 = r_emi_get_mem_addr_by_offset(0x1400);
  *(ushort *)(iVar7 + iVar5 + 2) = (ushort)((param_2 + 6U & 0xff) << 8) | uVar6 & 0xff;
  iVar7 = r_emi_get_mem_addr_by_offset(0x1400);
  *(undefined2 *)(iVar7 + iVar5 + 4) = param_3;
  if ((*(ushort *)(iVar10 + 0x74) & 4) == 0) {
    iVar10 = r_bt_rf_coex_st_param_get(2);
    if (iVar10 == 0) goto _L633;
    if (2 < _g_bt_plf_log_level) {
      uVar1 = *(undefined1 *)(iVar10 + 5);
      uVar2 = *(undefined1 *)(iVar10 + 4);
      pcVar8 = "TX PTI [LDC ADV] [EN%d] [%d] \n";
      goto _L666;
    }
  }
  else {
    iVar10 = r_bt_rf_coex_st_param_get(3);
    if (iVar10 == 0) goto _L633;
    if (2 < _g_bt_plf_log_level) {
      uVar1 = *(undefined1 *)(iVar10 + 5);
      uVar2 = *(undefined1 *)(iVar10 + 4);
      pcVar8 = "TX PTI [HDC ADV] [EN%d] [%d] \n";
_L666:
      ets_printf(pcVar8,uVar2,uVar1);
    }
  }
  uVar4 = (uint)*(byte *)(iVar10 + 5) << 8;
  if ((uVar4 & 0xf000) != 0) {
    r_assert_err(0,"lld_adv.c",0x33f);
  }
  iVar5 = iVar5 + 10;
  iVar7 = r_emi_get_mem_addr_by_offset(0x1400);
  uVar6 = *(ushort *)(iVar7 + iVar5);
  iVar7 = r_emi_get_mem_addr_by_offset(0x1400);
  *(ushort *)(iVar7 + iVar5) = uVar6 & 0xf0ff | (ushort)uVar4;
  bVar3 = *(byte *)(iVar10 + 4);
  iVar10 = r_emi_get_mem_addr_by_offset(0x1400);
  uVar6 = *(ushort *)(iVar10 + iVar5);
  iVar10 = r_emi_get_mem_addr_by_offset(0x1400);
  *(ushort *)(iVar5 + iVar10) = uVar6 & 0xefff | (ushort)bVar3 << 0xc;
_L633:
  if ((param_4 != 0) && (sVar9 != 0)) {
    if (param_5 != 0) {
      r_ble_util_buf_adv_tx_free_in_isr();
      return;
    }
    r_ble_util_buf_adv_tx_free(sVar9);
    return;
  }
  return;
}

