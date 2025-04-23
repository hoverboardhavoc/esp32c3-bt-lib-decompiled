/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> llm_hci.o -> hci_le_add_dev_to_rslv_list_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 hci_le_add_dev_to_rslv_list_cmd_handler(byte *param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 extraout_a1;
  uint uVar6;
  int iVar7;
  byte *__s1;
  
  uVar4 = 0x12;
  if (*param_1 < 2) {
    uVar5 = uVar4;
    if (*(char *)(_p_llm_env + 0xc6) != '\0') {
      iVar1 = r_llm_is_non_con_act_ongoing_check(0x12);
      uVar5 = 0xc;
      uVar4 = 0xc;
      if (iVar1 != 0) goto _L284;
    }
    iVar1 = 0;
    __s1 = param_1 + 1;
    while( true ) {
      iVar2 = r_sdk_config_get_opts(uVar5);
      if ((int)(uint)*(byte *)(iVar2 + 0xd) <= iVar1) break;
      iVar7 = *(int *)(_p_llm_env + 8) + iVar1 * 0x44;
      iVar2 = memcmp(__s1,(void *)(iVar7 + 4),6);
      if ((iVar2 == 0) && (*(char *)(iVar7 + 0x40) == '\t')) {
        uVar4 = 1;
        goto _L289;
      }
      iVar1 = iVar1 + 1;
      uVar5 = extraout_a1;
    }
    uVar4 = 0;
_L289:
    uVar3 = r_llm_dev_list_search(__s1,*param_1);
    uVar6 = 0;
    if (uVar3 < 0xc) {
      uVar6 = (int)(uint)*(byte *)(_p_llm_env + uVar3 * 10 + 0x2d) >> 1 & 1;
    }
    uVar4 = r_lld_res_list_add(__s1,param_1 + 7,param_1 + 0x17,*param_1,uVar4,uVar6);
  }
_L284:
  r_llm_cmd_cmp_send(param_2,uVar4);
  return 0;
}

