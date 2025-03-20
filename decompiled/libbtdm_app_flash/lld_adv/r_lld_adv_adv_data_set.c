/*
 * Last changed at upstream commit daab5dbba958a13041bd496e4a6ed506c9284a06
 * https://github.com/espressif/esp32c3-bt-lib/commit/daab5dbba958a13041bd496e4a6ed506c9284a06
 * Upstream date: 2025-03-20 20:43:40 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(86a4da5c)
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
  short sVar9;
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
  uVar4 = param_1 * 9 & 0xff;
  if ((*(ushort *)(iVar10 + 0x74) & 0x10) == 0) {
    sVar9 = 0;
    uVar5 = (**(code **)(_r_osi_funcs_p + 0x88))(*(code **)(_r_osi_funcs_p + 0x88));
    *(ushort *)(iVar10 + 0x76) = *(ushort *)(iVar10 + 0x76) & 0xf000 | uVar5 & 0xfff;
    if (param_4 != 0) {
      iVar6 = r_emi_get_mem_addr_by_offset(0x1400);
      sVar9 = *(short *)(iVar6 + (uVar4 + 1 & 0xff) * 0xe + 4);
    }
    *(short *)(iVar10 + 0x82) = (short)param_2;
    *(short *)(iVar10 + 0x7e) = (short)param_3;
    r_lld_adv_ext_chain_construct(*(undefined1 *)(iVar10 + 0x87));
    goto _L645;
  }
  iVar6 = uVar4 * 0xe;
  sVar9 = 0;
  if (param_4 != 0) {
    iVar7 = r_emi_get_mem_addr_by_offset(0x1400);
    sVar9 = *(short *)(iVar7 + iVar6 + 4);
  }
  iVar7 = r_emi_get_mem_addr_by_offset(0x1400);
  uVar5 = *(ushort *)(iVar7 + iVar6 + 2);
  iVar7 = r_emi_get_mem_addr_by_offset(0x1400);
  *(ushort *)(iVar7 + iVar6 + 2) = (ushort)((param_2 + 6U & 0xff) << 8) | uVar5 & 0xff;
  iVar7 = r_emi_get_mem_addr_by_offset(0x1400);
  *(short *)(iVar7 + iVar6 + 4) = (short)param_3;
  if ((*(ushort *)(iVar10 + 0x74) & 4) == 0) {
    iVar10 = r_bt_rf_coex_st_param_get(2);
    if (iVar10 == 0) goto _L645;
    if (2 < _g_bt_plf_log_level) {
      uVar1 = *(undefined1 *)(iVar10 + 5);
      uVar2 = *(undefined1 *)(iVar10 + 4);
      pcVar8 = "TX PTI [LDC ADV] [EN%d] [%d] \n";
      goto _L678;
    }
  }
  else {
    iVar10 = r_bt_rf_coex_st_param_get(3);
    if (iVar10 == 0) goto _L645;
    if (2 < _g_bt_plf_log_level) {
      uVar1 = *(undefined1 *)(iVar10 + 5);
      uVar2 = *(undefined1 *)(iVar10 + 4);
      pcVar8 = "TX PTI [HDC ADV] [EN%d] [%d] \n";
_L678:
      ets_printf(pcVar8,uVar2,uVar1);
    }
  }
  uVar4 = (uint)*(byte *)(iVar10 + 5) << 8;
  if ((uVar4 & 0xf000) != 0) {
    r_assert_err(0,"lld_adv.c",0x33f);
  }
  iVar6 = iVar6 + 10;
  iVar7 = r_emi_get_mem_addr_by_offset(0x1400);
  uVar5 = *(ushort *)(iVar7 + iVar6);
  iVar7 = r_emi_get_mem_addr_by_offset(0x1400);
  *(ushort *)(iVar7 + iVar6) = uVar5 & 0xf0ff | (ushort)uVar4;
  bVar3 = *(byte *)(iVar10 + 4);
  iVar10 = r_emi_get_mem_addr_by_offset(0x1400);
  uVar5 = *(ushort *)(iVar10 + iVar6);
  iVar10 = r_emi_get_mem_addr_by_offset(0x1400);
  *(ushort *)(iVar6 + iVar10) = uVar5 & 0xefff | (ushort)bVar3 << 0xc;
_L645:
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

