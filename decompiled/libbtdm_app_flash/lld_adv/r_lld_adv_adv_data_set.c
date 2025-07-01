/*
 * Last changed at upstream commit 0c68809d62e432427de97b5294f6619307f62f40
 * https://github.com/espressif/esp32c3-bt-lib/commit/0c68809d62e432427de97b5294f6619307f62f40
 * Upstream date: 2025-07-01 15:07:54 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(2edb0b0)
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
  int iVar9;
  ushort uVar10;
  
  iVar9 = *(int *)(&lld_adv_env + param_1 * 4);
  iVar6 = r_sdk_config_get_opts_ext();
  if ((*(uint *)(iVar6 + 0x28) & 4) != 0) {
    iVar6 = r_sdk_config_get_opts_ext();
    if (*(byte *)(iVar6 + 0x2c) < 3) {
      r_ble_log_internal_x2
                (0x40c0000f,param_4 << 0x10 | param_5 << 8 | param_2 << 0x18 | param_1,param_3);
    }
  }
  uVar10 = *(ushort *)(iVar9 + 0x74) & 0x10;
  uVar4 = param_1 * 9 & 0xff;
  if ((*(ushort *)(iVar9 + 0x74) & 0x10) == 0) {
    uVar5 = (**(code **)(_r_osi_funcs_p + 0x88))(*(code **)(_r_osi_funcs_p + 0x88));
    *(ushort *)(iVar9 + 0x76) = *(ushort *)(iVar9 + 0x76) & 0xf000 | uVar5 & 0xfff;
    if (param_4 != 0) {
      iVar6 = r_emi_get_mem_addr_by_offset(0x1400);
      uVar10 = *(ushort *)((uVar4 + 1 & 0xff) * 0xe + 4 + iVar6);
    }
    *(short *)(iVar9 + 0x82) = (short)param_2;
    *(short *)(iVar9 + 0x7e) = (short)param_3;
    r_lld_adv_ext_chain_construct(*(undefined1 *)(iVar9 + 0x87));
    goto _L651;
  }
  iVar6 = uVar4 * 0xe;
  uVar10 = 0;
  if (param_4 != 0) {
    iVar7 = r_emi_get_mem_addr_by_offset(0x1400);
    uVar10 = *(ushort *)(iVar7 + iVar6 + 4);
  }
  iVar7 = r_emi_get_mem_addr_by_offset(0x1400);
  uVar5 = *(ushort *)(iVar7 + iVar6 + 2);
  iVar7 = r_emi_get_mem_addr_by_offset(0x1400);
  *(ushort *)(iVar7 + iVar6 + 2) = (ushort)((param_2 + 6U & 0xff) << 8) | uVar5 & 0xff;
  iVar7 = r_emi_get_mem_addr_by_offset(0x1400);
  *(short *)(iVar7 + iVar6 + 4) = (short)param_3;
  if ((*(ushort *)(iVar9 + 0x74) & 4) == 0) {
    iVar9 = r_bt_rf_coex_st_param_get(2);
    if (iVar9 == 0) goto _L651;
    if (2 < _g_bt_plf_log_level) {
      uVar1 = *(undefined1 *)(iVar9 + 5);
      uVar2 = *(undefined1 *)(iVar9 + 4);
      pcVar8 = "TX PTI [LDC ADV] [EN%d] [%d] \n";
      goto _L685;
    }
  }
  else {
    iVar9 = r_bt_rf_coex_st_param_get(3);
    if (iVar9 == 0) goto _L651;
    if (2 < _g_bt_plf_log_level) {
      uVar1 = *(undefined1 *)(iVar9 + 5);
      uVar2 = *(undefined1 *)(iVar9 + 4);
      pcVar8 = "TX PTI [HDC ADV] [EN%d] [%d] \n";
_L685:
      ets_printf(pcVar8,uVar2,uVar1);
    }
  }
  uVar4 = (uint)*(byte *)(iVar9 + 5) << 8;
  if ((uVar4 & 0xf000) != 0) {
    r_assert_err(0,0x10000,0x33f);
  }
  iVar7 = r_emi_get_mem_addr_by_offset(0x1400);
  iVar6 = iVar6 + 10;
  uVar5 = *(ushort *)(iVar7 + iVar6);
  iVar7 = r_emi_get_mem_addr_by_offset(0x1400);
  *(ushort *)(iVar7 + iVar6) = uVar5 & 0xf0ff | (ushort)uVar4;
  bVar3 = *(byte *)(iVar9 + 4);
  iVar9 = r_emi_get_mem_addr_by_offset(0x1400);
  uVar5 = *(ushort *)(iVar9 + iVar6);
  iVar9 = r_emi_get_mem_addr_by_offset(0x1400);
  *(ushort *)(iVar9 + iVar6) = uVar5 & 0xefff | (ushort)bVar3 << 0xc;
_L651:
  if ((param_4 != 0) && (uVar10 != 0)) {
    if (param_5 != 0) {
      r_ble_util_buf_adv_tx_free_in_isr();
      return;
    }
    r_ble_util_buf_adv_tx_free(uVar10);
    return;
  }
  return;
}

