/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> lld_adv.o -> r_lld_adv_scan_rsp_data_set
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_adv_scan_rsp_data_set
               (uint param_1,int param_2,undefined4 param_3,int param_4,int param_5)

{
  byte bVar1;
  uint uVar2;
  ushort uVar3;
  int iVar4;
  int iVar5;
  ushort uVar6;
  int iVar7;
  
  iVar5 = *(int *)(&lld_adv_env + param_1 * 4);
  iVar4 = r_sdk_config_get_opts_ext();
  if ((*(uint *)(iVar4 + 0x28) & 4) != 0) {
    iVar4 = r_sdk_config_get_opts_ext();
    if (*(byte *)(iVar4 + 0x2c) < 3) {
      r_ble_log_internal_x2
                (0x40c00010,param_4 << 0x10 | param_5 << 8 | param_2 << 0x18 | param_1,param_3);
    }
  }
  uVar6 = *(ushort *)(iVar5 + 0x74) & 0x10;
  uVar2 = param_1 * 9 & 0xff;
  if ((*(ushort *)(iVar5 + 0x74) & 0x10) == 0) {
    uVar3 = (**(code **)(_r_osi_funcs_p + 0x88))(*(code **)(_r_osi_funcs_p + 0x88));
    *(ushort *)(iVar5 + 0x76) = *(ushort *)(iVar5 + 0x76) & 0xf000 | uVar3 & 0xfff;
    if (param_4 != 0) {
      iVar4 = r_emi_get_mem_addr_by_offset(0x1400);
      uVar6 = *(ushort *)((uVar2 + 2 & 0xff) * 0xe + 4 + iVar4);
    }
    *(short *)(iVar5 + 0x84) = (short)param_2;
    *(short *)(iVar5 + 0x80) = (short)param_3;
    r_lld_adv_ext_chain_construct(*(undefined1 *)(iVar5 + 0x87));
  }
  else {
    iVar4 = (uVar2 + 1 & 0xff) * 0xe;
    uVar6 = 0;
    if (param_4 != 0) {
      iVar5 = r_emi_get_mem_addr_by_offset(0x1400);
      uVar6 = *(ushort *)(iVar5 + iVar4 + 4);
    }
    iVar5 = r_emi_get_mem_addr_by_offset(0x1400);
    iVar7 = iVar4 + 2;
    uVar3 = *(ushort *)(iVar5 + iVar7);
    iVar5 = r_emi_get_mem_addr_by_offset(0x1400);
    *(ushort *)(iVar5 + iVar7) = uVar3 & 0xfff0 | 4;
    iVar5 = r_emi_get_mem_addr_by_offset(0x1400);
    uVar3 = *(ushort *)(iVar5 + iVar7);
    iVar5 = r_emi_get_mem_addr_by_offset(0x1400);
    *(ushort *)(iVar5 + iVar7) = (ushort)((param_2 + 6U & 0xff) << 8) | uVar3 & 0xff;
    iVar5 = r_emi_get_mem_addr_by_offset(0x1400);
    *(short *)(iVar5 + iVar4 + 4) = (short)param_3;
    iVar5 = r_emi_get_mem_addr_by_offset(0x1400);
    uVar3 = *(ushort *)(iVar5 + iVar4);
    iVar5 = r_emi_get_mem_addr_by_offset();
    *(ushort *)(iVar5 + iVar4) = (short)uVar2 * 0xe + 0x1400U | uVar3 & 0x8000;
    iVar5 = r_bt_rf_coex_st_param_get(2);
    if (iVar5 != 0) {
      if (2 < _g_bt_plf_log_level) {
        ets_printf("TX PTI [LDC SCANRSP] [EN%d] [%d] \n",*(undefined1 *)(iVar5 + 4),
                   *(undefined1 *)(iVar5 + 5));
      }
      bVar1 = *(byte *)(iVar5 + 5);
      if ((bVar1 & 0xf0) != 0) {
        r_assert_err(0,0x10000,0x33f);
      }
      iVar7 = r_emi_get_mem_addr_by_offset(0x1400);
      iVar4 = iVar4 + 10;
      uVar3 = *(ushort *)(iVar7 + iVar4);
      iVar7 = r_emi_get_mem_addr_by_offset(0x1400);
      *(ushort *)(iVar7 + iVar4) = uVar3 & 0xf0ff | (ushort)bVar1 << 8;
      bVar1 = *(byte *)(iVar5 + 4);
      iVar5 = r_emi_get_mem_addr_by_offset(0x1400);
      uVar3 = *(ushort *)(iVar5 + iVar4);
      iVar5 = r_emi_get_mem_addr_by_offset(0x1400);
      *(ushort *)(iVar5 + iVar4) = uVar3 & 0xefff | (ushort)bVar1 << 0xc;
    }
  }
  if ((param_4 != 0) && (uVar6 != 0)) {
    if (param_5 != 0) {
      r_ble_util_buf_adv_tx_free_in_isr();
      return;
    }
    r_ble_util_buf_adv_tx_free(uVar6);
    return;
  }
  return;
}

