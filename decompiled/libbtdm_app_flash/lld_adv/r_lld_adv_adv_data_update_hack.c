/*
 * Last changed at upstream commit 72599d583c232ea78d6461b5b502426c6e5a1ec9
 * https://github.com/espressif/esp32c3-bt-lib/commit/72599d583c232ea78d6461b5b502426c6e5a1ec9
 * Upstream date: 2025-05-19 16:27:45 +0800
 * Upstream subject: Update bt lib for ESP32-C3 and ESP32-S3(6cfabcd8)
 * Source: libbtdm_app_flash -> lld_adv.o -> r_lld_adv_adv_data_update_hack
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_adv_adv_data_update_hack(uint param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  
  iVar2 = param_1 * 4;
  (**(code **)(_r_osi_funcs_p + 0x14))(*(code **)(_r_osi_funcs_p + 0x14));
  if (*(int *)(&lld_adv_env + iVar2) == 0) {
    iVar2 = ke_msg_is_in_queue(0x207);
    if (iVar2 == 0) {
      r_assert_param(param_1,0,0x10000,0xda7);
    }
  }
  else {
    iVar1 = r_sdk_config_get_opts_ext();
    if ((*(uint *)(iVar1 + 0x28) & 4) != 0) {
      iVar1 = r_sdk_config_get_opts_ext();
      if (*(byte *)(iVar1 + 0x2c) < 3) {
        r_ble_log_internal_x2
                  (0x40c0000d,
                   (uint)*(byte *)(*(int *)(&lld_adv_env + iVar2) + 0x89) << 8 |
                   param_2 << 0x10 | param_1,param_3);
      }
    }
    if (*(char *)(*(int *)(&lld_adv_env + iVar2) + 0x89) == '\0') {
      r_lld_adv_adv_data_set_hack(param_1,param_2,param_3,1);
    }
    else {
      if (*(short *)(*(int *)(&lld_adv_env + iVar2) + 0x24) != 0) {
        r_ble_util_buf_adv_tx_free();
      }
      iVar2 = *(int *)(&lld_adv_env + iVar2);
      *(short *)(iVar2 + 0x28) = (short)param_2;
      *(short *)(iVar2 + 0x24) = (short)param_3;
      if (param_2 == 0) {
        adv_adv_data_need_to_set[param_1] = 1;
      }
    }
  }
                    /* WARNING: Could not recover jumptable at 0x00015a1c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_osi_funcs_p + 0x18))(*(code **)(_r_osi_funcs_p + 0x18));
  return;
}

