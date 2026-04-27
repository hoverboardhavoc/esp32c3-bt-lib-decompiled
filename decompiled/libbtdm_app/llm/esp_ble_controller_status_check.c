/*
 * Last changed at upstream commit 58d499bba1019a80a622df60aa38f59c1e4565ba
 * https://github.com/espressif/esp32c3-bt-lib/commit/58d499bba1019a80a622df60aa38f59c1e4565ba
 * Upstream date: 2026-04-27 15:45:42 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(2f683593)
 * Source: libbtdm_app -> llm.o -> esp_ble_controller_status_check
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint esp_ble_controller_status_check(void)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  char *pcVar6;
  byte *pbVar7;
  uint uVar8;
  undefined4 uStack_28;
  undefined2 uStack_24;
  
  uVar2 = 0;
  for (uVar3 = 0; iVar4 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38)),
      uVar3 < *(byte *)(iVar4 + 0xd); uVar3 = uVar3 + 1 & 0xff) {
    uVar8 = (uint)*(byte *)(*(int *)(_p_llm_env + 8) + uVar3 * 0x44 + 0x40);
    if ((-0x454 >> (uVar8 & 0x1f) & 1U) != 0) {
      uVar2 = uVar2 | 1 << (uVar8 & 0x1f);
    }
  }
  pbVar7 = (byte *)(_p_llm_env + 0x2d);
  do {
    bVar1 = *pbVar7;
    if (bVar1 != 0) {
      if ((bVar1 & 2) != 0) {
        uVar2 = uVar2 | 0x20000;
      }
      if ((bVar1 & 4) != 0) {
        uVar2 = uVar2 | 2;
      }
      break;
    }
    pbVar7 = pbVar7 + 10;
  } while ((byte *)(_p_llm_env + 0xa5) != pbVar7);
  iVar4 = 0;
  while ((iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0xc60,*(code **)(_r_plf_funcs_p + 0xbc)),
         -1 < *(short *)(iVar4 * 0x34 + iVar5) || (iVar4 == 0))) {
    iVar4 = iVar4 + 1;
    if (iVar4 == 10) {
_L241:
      if (g_scan_forever != '\0') {
        uVar2 = uVar2 | 0x80000;
      }
      if (g_adv_delay_dis != '\0') {
        uVar2 = uVar2 | 0x100000;
      }
      iVar4 = lld_phy_coded_500k_get();
      if (iVar4 != 0) {
        uVar2 = uVar2 | 0x200000;
      }
      pcVar6 = (char *)(**(code **)(_r_ip_funcs_p + 0x914))(*(code **)(_r_ip_funcs_p + 0x914));
      if (pcVar6 != (char *)0x0) {
        if (*pcVar6 != '\0') {
          uVar2 = uVar2 | 0x400000;
        }
        if (*(int *)(pcVar6 + 0x10) != 0) {
          uVar2 = uVar2 | 0x800000;
        }
        if (*(int *)(pcVar6 + 0x14) != 0) {
          uVar2 = uVar2 | 0x1000000;
        }
        if (*(short *)(pcVar6 + 0x20) == 1) {
          uVar2 = uVar2 | 0x2000000;
        }
        if (*(short *)(pcVar6 + 0x18) != 0) {
          uVar2 = uVar2 | 0x4000000;
        }
        uStack_28 = 0;
        uStack_24 = 0;
        iVar4 = memcmp(pcVar6 + 2,&uStack_28,6);
        if (iVar4 != 0) {
          uVar2 = uVar2 | 0x8000000;
        }
      }
      iVar4 = ble_ll_rand_addr_check();
      if (iVar4 != 0) {
        uVar2 = uVar2 | 0x10000000;
      }
      iVar4 = lld_le_pkt_err_state_check();
      if (iVar4 != 0) {
        uVar2 = uVar2 | 0x20000000;
      }
      iVar4 = lld_fixed_ch_idx_state_check();
      if (iVar4 != 0) {
        uVar2 = uVar2 | 0x40000000;
      }
      if (privacy_en == '\0') {
        uVar2 = uVar2 | 0x80000000;
      }
      iVar4 = lld_dtm_is_ongoing();
      if (iVar4 != 0) {
        uVar2 = uVar2 | 1;
      }
      return uVar2;
    }
  }
  uVar2 = uVar2 | 0x40000;
  goto _L241;
}

