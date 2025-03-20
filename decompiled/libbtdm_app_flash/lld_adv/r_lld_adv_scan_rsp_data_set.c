/*
 * Last changed at upstream commit d2414a5dd958b32ca53382b441d24d97a0345a55
 * https://github.com/espressif/esp32c3-bt-lib/commit/d2414a5dd958b32ca53382b441d24d97a0345a55
 * Upstream date: 2025-03-20 20:11:19 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(03d0f8a6)
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
  int iVar3;
  ushort uVar4;
  int iVar5;
  short sVar6;
  int iVar7;
  
  iVar3 = *(int *)(&lld_adv_env + param_1 * 4);
  iVar5 = r_sdk_config_get_opts_ext();
  if ((*(uint *)(iVar5 + 0x28) & 4) != 0) {
    iVar5 = r_sdk_config_get_opts_ext();
    if (*(byte *)(iVar5 + 0x2c) < 3) {
      r_ble_log_internal_x2
                (0x40c00010,param_4 << 0x10 | param_5 << 8 | param_2 << 0x18 | param_1,param_3);
    }
  }
  uVar2 = param_1 * 9 & 0xff;
  if ((*(ushort *)(iVar3 + 0x74) & 0x10) == 0) {
    sVar6 = 0;
    uVar4 = (**(code **)(_r_osi_funcs_p + 0x88))(*(code **)(_r_osi_funcs_p + 0x88));
    *(ushort *)(iVar3 + 0x76) = *(ushort *)(iVar3 + 0x76) & 0xf000 | uVar4 & 0xfff;
    if (param_4 != 0) {
      iVar5 = r_emi_get_mem_addr_by_offset(0x1400);
      sVar6 = *(short *)(iVar5 + (uVar2 + 2 & 0xff) * 0xe + 4);
    }
    *(short *)(iVar3 + 0x84) = (short)param_2;
    *(short *)(iVar3 + 0x80) = (short)param_3;
    r_lld_adv_ext_chain_construct(*(undefined1 *)(iVar3 + 0x87));
  }
  else {
    iVar3 = (uVar2 + 1 & 0xff) * 0xe;
    sVar6 = 0;
    if (param_4 != 0) {
      iVar5 = r_emi_get_mem_addr_by_offset(0x1400);
      sVar6 = *(short *)(iVar5 + iVar3 + 4);
    }
    iVar5 = r_emi_get_mem_addr_by_offset(0x1400);
    iVar7 = iVar3 + 2;
    uVar4 = *(ushort *)(iVar5 + iVar7);
    iVar5 = r_emi_get_mem_addr_by_offset(0x1400);
    *(ushort *)(iVar5 + iVar7) = uVar4 & 0xfff0 | 4;
    iVar5 = r_emi_get_mem_addr_by_offset(0x1400);
    uVar4 = *(ushort *)(iVar5 + iVar7);
    iVar5 = r_emi_get_mem_addr_by_offset(0x1400);
    *(ushort *)(iVar5 + iVar7) = (ushort)((param_2 + 6U & 0xff) << 8) | uVar4 & 0xff;
    iVar5 = r_emi_get_mem_addr_by_offset(0x1400);
    *(short *)(iVar5 + iVar3 + 4) = (short)param_3;
    iVar5 = r_emi_get_mem_addr_by_offset(0x1400);
    uVar4 = *(ushort *)(iVar5 + iVar3);
    iVar5 = r_emi_get_mem_addr_by_offset();
    *(ushort *)(iVar5 + iVar3) = (short)uVar2 * 0xe + 0x1400U | uVar4 & 0x8000;
    iVar5 = r_bt_rf_coex_st_param_get(2);
    if (iVar5 != 0) {
      if (2 < _g_bt_plf_log_level) {
        ets_printf("TX PTI [LDC SCANRSP] [EN%d] [%d] \n",*(undefined1 *)(iVar5 + 4),
                   *(undefined1 *)(iVar5 + 5));
      }
      uVar2 = (uint)*(byte *)(iVar5 + 5) << 8;
      if ((uVar2 & 0xf000) != 0) {
        r_assert_err(0,"lld_adv.c",0x33f);
      }
      iVar3 = iVar3 + 10;
      iVar7 = r_emi_get_mem_addr_by_offset(0x1400);
      uVar4 = *(ushort *)(iVar7 + iVar3);
      iVar7 = r_emi_get_mem_addr_by_offset(0x1400);
      *(ushort *)(iVar7 + iVar3) = uVar4 & 0xf0ff | (ushort)uVar2;
      bVar1 = *(byte *)(iVar5 + 4);
      iVar5 = r_emi_get_mem_addr_by_offset(0x1400);
      uVar4 = *(ushort *)(iVar5 + iVar3);
      iVar5 = r_emi_get_mem_addr_by_offset(0x1400);
      *(ushort *)(iVar3 + iVar5) = uVar4 & 0xefff | (ushort)bVar1 << 0xc;
    }
  }
  if ((param_4 != 0) && (sVar6 != 0)) {
    if (param_5 != 0) {
      r_ble_util_buf_adv_tx_free_in_isr();
      return;
    }
    r_ble_util_buf_adv_tx_free(sVar6);
    return;
  }
  return;
}

