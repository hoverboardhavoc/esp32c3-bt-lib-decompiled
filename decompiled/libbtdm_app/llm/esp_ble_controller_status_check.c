/*
 * Last changed at upstream commit e5c0f7256ecf5b5f8eb28c1793051a6b88f95124
 * https://github.com/espressif/esp32c3-bt-lib/commit/e5c0f7256ecf5b5f8eb28c1793051a6b88f95124
 * Upstream date: 2024-02-04 11:46:50 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(30b57c45)
 * Source: libbtdm_app -> llm.o -> esp_ble_controller_status_check
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint esp_ble_controller_status_check(void)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  char *pcVar5;
  uint uVar6;
  undefined4 uStack_38;
  undefined2 uStack_34;
  
  uVar1 = 0;
  for (uVar2 = 0; iVar3 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38)),
      uVar2 < *(byte *)(iVar3 + 0xd); uVar2 = uVar2 + 1 & 0xff) {
    uVar6 = (uint)*(byte *)(*(int *)(_p_llm_env + 8) + uVar2 * 0x44 + 0x40);
    if ((-0x454 >> (uVar6 & 0x1f) & 1U) != 0) {
      uVar1 = uVar1 | 1 << (uVar6 & 0x1f);
    }
  }
  pcVar5 = (char *)(_p_llm_env + 0x2d);
  do {
    if (*pcVar5 != '\0') {
      uVar1 = uVar1 | 0x20000;
      break;
    }
    pcVar5 = pcVar5 + 10;
  } while (pcVar5 != (char *)(_p_llm_env + 0xa5));
  iVar3 = 0;
  while ((iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0xc60,*(code **)(_r_plf_funcs_p + 0xbc)),
         -1 < *(short *)(iVar4 + iVar3 * 0x34) || (iVar3 == 0))) {
    iVar3 = iVar3 + 1;
    if (iVar3 == 10) {
_L226:
      if (g_scan_forever != '\0') {
        uVar1 = uVar1 | 0x80000;
      }
      if (g_adv_delay_dis != '\0') {
        uVar1 = uVar1 | 0x100000;
      }
      iVar3 = lld_phy_coded_500k_get();
      if (iVar3 != 0) {
        uVar1 = uVar1 | 0x200000;
      }
      pcVar5 = (char *)(**(code **)(_r_ip_funcs_p + 0x914))(*(code **)(_r_ip_funcs_p + 0x914));
      if (pcVar5 != (char *)0x0) {
        if (*pcVar5 != '\0') {
          uVar1 = uVar1 | 0x400000;
        }
        if (*(int *)(pcVar5 + 0x10) != 0) {
          uVar1 = uVar1 | 0x800000;
        }
        if (*(int *)(pcVar5 + 0x14) != 0) {
          uVar1 = uVar1 | 0x1000000;
        }
        if (pcVar5[1] != '\0') {
          uVar1 = uVar1 | 0x2000000;
        }
        if (*(short *)(pcVar5 + 0x18) != 0) {
          uVar1 = uVar1 | 0x4000000;
        }
        uStack_38 = 0;
        uStack_34 = 0;
        iVar3 = memcmp(pcVar5 + 2,&uStack_38,6);
        if (iVar3 != 0) {
          uVar1 = uVar1 | 0x8000000;
        }
      }
      iVar3 = ble_ll_rand_addr_check();
      if (iVar3 != 0) {
        uVar1 = uVar1 | 0x10000000;
      }
      iVar3 = lld_le_pkt_err_state_check();
      if (iVar3 != 0) {
        uVar1 = uVar1 | 0x20000000;
      }
      iVar3 = lld_fixed_ch_idx_state_check();
      if (iVar3 != 0) {
        uVar1 = uVar1 | 0x40000000;
      }
      if (privacy_en == '\0') {
        uVar1 = uVar1 | 0x80000000;
      }
      iVar3 = lld_dtm_is_ongoing();
      if (iVar3 != 0) {
        uVar1 = uVar1 | 1;
      }
      return uVar1;
    }
  }
  uVar1 = uVar1 | 0x40000;
  goto _L226;
}

