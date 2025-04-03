/*
 * Last changed at upstream commit f23a340e82d6a4be40f83214385a98c5bd30ccdd
 * https://github.com/espressif/esp32c3-bt-lib/commit/f23a340e82d6a4be40f83214385a98c5bd30ccdd
 * Upstream date: 2025-04-03 18:07:15 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(a684dd5)
 * Source: libbtdm_app_flash -> llm.o -> r_llm_ch_map_update
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_llm_ch_map_update(void)

{
  bool bVar1;
  code cVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  byte bVar9;
  uint uVar10;
  int iVar11;
  int iVar12;
  uint uVar13;
  uint uVar14;
  
  iVar3 = r_lld_read_clock();
  iVar5 = _p_llm_env;
  iVar4 = r_lld_ch_assess_data_get();
  cVar2 = r_hci_ble_conhdl_unregister;
  iVar11 = _p_llm_env;
  uVar13 = (uint)_DAT_000120ba;
  uVar14 = (uint)_r_lld_res_list_peer_update;
  iVar12 = iVar5 + 0x1d;
  uVar6 = 0;
  do {
    iVar7 = ((int)uVar6 >> 3) + iVar5;
    uVar10 = uVar6 & 7;
    if (((int)(uint)*(byte *)(iVar7 + 0x18) >> uVar10 & 1U) == 0) {
_L403:
      bVar9 = ~(byte)(1 << uVar10) & *(byte *)(iVar7 + 0x1d);
_L402:
      *(byte *)(iVar7 + 0x1d) = bVar9;
    }
    else if (*(char *)(iVar11 + 0xd9) != '\0') {
      uVar8 = iVar3 - *(int *)(uVar6 * 4 + iVar4) & 0xfffffff;
      if (uVar8 < uVar13) {
        if (*(char *)(iVar4 + uVar6 + 0x94) <= (char)cVar2) goto _L403;
      }
      else {
        *(undefined1 *)(iVar4 + uVar6 + 0x94) = 0;
        if (uVar14 < uVar8) {
          bVar9 = (byte)(1 << uVar10) | *(byte *)(iVar7 + 0x1d);
          goto _L402;
        }
      }
    }
    uVar6 = uVar6 + 1;
  } while (uVar6 != 0x25);
  uVar6 = r_co_nb_good_le_channels(iVar12);
  if (uVar6 < 2) {
    uVar13 = 0;
    do {
      iVar11 = ((int)uVar13 >> 3) + iVar5;
      uVar14 = uVar13 & 7;
      if ((((int)(uint)*(byte *)(iVar11 + 0x18) >> uVar14 & 1U) != 0) &&
         (((int)(uint)*(byte *)(iVar11 + 0x1d) >> uVar14 & 1U) == 0)) {
        *(byte *)(iVar11 + 0x1d) = (byte)(1 << uVar14) | *(byte *)(iVar11 + 0x1d);
        if (uVar6 == 1) break;
        uVar6 = 1;
      }
      uVar13 = uVar13 + 1;
    } while (uVar13 != 0x25);
  }
  r_lld_ch_map_set(iVar12);
  bVar1 = false;
  for (uVar6 = 0; iVar5 = r_sdk_config_get_opts(), (int)uVar6 < (int)(uint)*(byte *)(iVar5 + 0xd);
      uVar6 = uVar6 + 1) {
    iVar5 = *(int *)(_p_llm_env + 8) + uVar6 * 0x44;
    if ((*(char *)(iVar5 + 0x40) == '\t') && (*(char *)(iVar5 + 0x28) == '\0')) {
      r_ke_msg_send_basic(2,(uVar6 & 0xff) << 8 | 1,0);
      bVar1 = true;
    }
    if (*(char *)(*(int *)(_p_llm_env + 8) + uVar6 * 0x44 + 0x40) == '\f') {
      iVar5 = r_sdk_config_get_opts_ext();
      if (*(char *)(iVar5 + 0x18) == '\0') {
        r_assert_err(0,"llm.c",0x502);
      }
      r_lld_per_adv_ch_map_update(uVar6 & 0xff,iVar12);
    }
  }
  if (bVar1) {
    r_ke_timer_set(4,0,(uint)_r_lld_white_list_add * 100);
    return;
  }
  *(undefined1 *)(_p_llm_env + 0x22) = 0;
  return;
}

