/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> lld_adv.o -> r_lld_adv_adv_data_set
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_adv_adv_data_set(uint param_1,int param_2,undefined4 param_3,int param_4,int param_5)

{
  undefined1 uVar1;
  undefined1 uVar2;
  byte bVar3;
  uint uVar4;
  ushort uVar5;
  int iVar6;
  int iVar7;
  char *pcVar8;
  ushort uVar9;
  int iVar10;
  
  iVar10 = *(int *)(&lld_adv_env + param_1 * 4);
  iVar6 = r_sdk_config_get_opts_ext();
  if ((*(uint *)(iVar6 + 0x28) & 4) != 0) {
    iVar6 = r_sdk_config_get_opts_ext();
    if (*(byte *)(iVar6 + 0x2c) < 3) {
      r_ble_log_internal_x2
                (0x40c0000f,param_4 << 0x10 | param_5 << 8 | param_2 << 0x18 | param_1,param_3);
    }
  }
  uVar9 = *(ushort *)(iVar10 + 0x74) & 0x10;
  uVar4 = param_1 * 9 & 0xff;
  if ((*(ushort *)(iVar10 + 0x74) & 0x10) == 0) {
    uVar5 = (**(code **)(_r_osi_funcs_p + 0x88))(*(code **)(_r_osi_funcs_p + 0x88));
    *(ushort *)(iVar10 + 0x76) = *(ushort *)(iVar10 + 0x76) & 0xf000 | uVar5 & 0xfff;
    if (param_4 != 0) {
      iVar6 = r_emi_get_mem_addr_by_offset(0x1400);
      uVar9 = *(ushort *)((uVar4 + 1 & 0xff) * 0xe + 4 + iVar6);
    }
    *(short *)(iVar10 + 0x82) = (short)param_2;
    *(short *)(iVar10 + 0x7e) = (short)param_3;
    r_lld_adv_ext_chain_construct(*(undefined1 *)(iVar10 + 0x87));
    goto _L582;
  }
  iVar6 = uVar4 * 0xe;
  uVar9 = 0;
  if (param_4 != 0) {
    iVar7 = r_emi_get_mem_addr_by_offset(0x1400);
    uVar9 = *(ushort *)(iVar7 + iVar6 + 4);
  }
  iVar7 = r_emi_get_mem_addr_by_offset(0x1400);
  uVar5 = *(ushort *)(iVar7 + iVar6 + 2);
  iVar7 = r_emi_get_mem_addr_by_offset(0x1400);
  *(ushort *)(iVar7 + iVar6 + 2) = (ushort)((param_2 + 6U & 0xff) << 8) | uVar5 & 0xff;
  iVar7 = r_emi_get_mem_addr_by_offset(0x1400);
  *(short *)(iVar7 + iVar6 + 4) = (short)param_3;
  if ((*(ushort *)(iVar10 + 0x74) & 4) == 0) {
    iVar10 = r_bt_rf_coex_st_param_get(2);
    if (iVar10 == 0) goto _L582;
    if (2 < _g_bt_plf_log_level) {
      uVar1 = *(undefined1 *)(iVar10 + 5);
      uVar2 = *(undefined1 *)(iVar10 + 4);
      pcVar8 = "TX PTI [LDC ADV] [EN%d] [%d] \n";
      goto _L614;
    }
  }
  else {
    iVar10 = r_bt_rf_coex_st_param_get(3);
    if (iVar10 == 0) goto _L582;
    if (2 < _g_bt_plf_log_level) {
      uVar1 = *(undefined1 *)(iVar10 + 5);
      uVar2 = *(undefined1 *)(iVar10 + 4);
      pcVar8 = "TX PTI [HDC ADV] [EN%d] [%d] \n";
_L614:
      ets_printf(pcVar8,uVar2,uVar1);
    }
  }
  bVar3 = *(byte *)(iVar10 + 5);
  if ((bVar3 & 0xf0) != 0) {
    r_assert_err(0,0x10000,0x33f);
  }
  iVar7 = r_emi_get_mem_addr_by_offset(0x1400);
  iVar6 = iVar6 + 10;
  uVar5 = *(ushort *)(iVar7 + iVar6);
  iVar7 = r_emi_get_mem_addr_by_offset(0x1400);
  *(ushort *)(iVar7 + iVar6) = uVar5 & 0xf0ff | (ushort)bVar3 << 8;
  bVar3 = *(byte *)(iVar10 + 4);
  iVar10 = r_emi_get_mem_addr_by_offset(0x1400);
  uVar5 = *(ushort *)(iVar10 + iVar6);
  iVar10 = r_emi_get_mem_addr_by_offset(0x1400);
  *(ushort *)(iVar10 + iVar6) = uVar5 & 0xefff | (ushort)bVar3 << 0xc;
_L582:
  if ((param_4 != 0) && (uVar9 != 0)) {
    if (param_5 != 0) {
      r_ble_util_buf_adv_tx_free_in_isr();
      return;
    }
    r_ble_util_buf_adv_tx_free(uVar9);
    return;
  }
  return;
}

