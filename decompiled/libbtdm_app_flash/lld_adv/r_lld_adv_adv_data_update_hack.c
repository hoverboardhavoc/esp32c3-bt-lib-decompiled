/*
 * Last changed at upstream commit 58d499bba1019a80a622df60aa38f59c1e4565ba
 * https://github.com/espressif/esp32c3-bt-lib/commit/58d499bba1019a80a622df60aa38f59c1e4565ba
 * Upstream date: 2026-04-27 15:45:42 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(2f683593)
 * Source: libbtdm_app_flash -> lld_adv.o -> r_lld_adv_adv_data_update_hack
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_adv_adv_data_update_hack(int param_1,int param_2,uint param_3)

{
  int iVar1;
  
  (**(code **)(_r_osi_funcs_p + 0x14))(*(code **)(_r_osi_funcs_p + 0x14));
  iVar1 = *(int *)(&lld_adv_env + param_1 * 4);
  if (iVar1 == 0) {
    iVar1 = ke_msg_is_in_queue(0x207);
    if (iVar1 == 0) {
      r_assert_param(param_1,0,0x10000,0xe3e);
    }
  }
  else {
    r_ble_log_internal_x2
              (0x40c000ef,param_1 << 0x10 | param_3 | (uint)*(byte *)(iVar1 + 0x89) << 0x18,param_2)
    ;
    iVar1 = *(int *)(&lld_adv_env + param_1 * 4);
    if (*(char *)(iVar1 + 0x89) == '\0') {
      r_lld_adv_adv_data_set_hack(param_1,param_2,param_3,1);
    }
    else {
      if (*(short *)(iVar1 + 0x24) != 0) {
        r_ble_util_buf_adv_tx_free();
      }
      iVar1 = *(int *)(&lld_adv_env + param_1 * 4);
      *(short *)(iVar1 + 0x28) = (short)param_2;
      *(short *)(iVar1 + 0x24) = (short)param_3;
      if (param_2 == 0) {
        adv_adv_data_need_to_set[param_1] = 1;
      }
    }
  }
                    /* WARNING: Could not recover jumptable at 0x00015ee8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_osi_funcs_p + 0x18))(*(code **)(_r_osi_funcs_p + 0x18));
  return;
}

