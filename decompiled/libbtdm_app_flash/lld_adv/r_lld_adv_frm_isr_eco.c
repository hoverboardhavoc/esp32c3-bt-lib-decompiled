/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> lld_adv.o -> r_lld_adv_frm_isr_eco
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_adv_frm_isr_eco(uint param_1,undefined4 param_2,int param_3)

{
  bool bVar1;
  bool bVar2;
  bool bVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  undefined4 unaff_s5;
  
  iVar4 = *(int *)(&lld_adv_env + param_1 * 4);
  bVar3 = false;
  if (iVar4 != 0) {
    bVar1 = *(uint *)(iVar4 + 100) < 0x20;
    bVar2 = g_adv_delay_dis == '\0';
    bVar3 = bVar1 && bVar2;
    iVar5 = r_sdk_config_get_opts_ext();
    if (((*(uint *)(iVar5 + 0x28) & 4) != 0) &&
       (iVar5 = r_sdk_config_get_opts_ext(), *(byte *)(iVar5 + 0x2c) < 3)) {
      r_ble_log_internal_x1
                (0x40400009,(uint)*(byte *)(iVar4 + 0x89) << 0x10 | param_3 << 8 | param_1);
    }
    if ((param_3 == 0) && (g_ble_ext_config != '\0')) {
      DAT_00016568 = DAT_00016568 + 1;
    }
    if (bVar1 && bVar2) {
      g_adv_delay_dis = '\x01';
      unaff_s5 = *(undefined4 *)(iVar4 + 100);
      uVar6 = (**(code **)(_r_osi_funcs_p + 0x88))(*(code **)(_r_osi_funcs_p + 0x88));
      uVar6 = uVar6 % 9;
      iVar5 = uVar6 << 1;
      if (*(char *)(iVar4 + 0x95) != '\0') {
        if (uVar6 == 0) {
          iVar5 = 1;
        }
        else if (uVar6 == 8) {
          iVar5 = 0xf;
        }
      }
      *(uint *)(iVar4 + 100) = (uint)(*(int *)(iVar4 + 100) * 2 + iVar5) >> 1;
    }
  }
  if ((adv_adv_data_need_to_set[param_1] != '\0') &&
     (((*(ushort *)(iVar4 + 0x74) & 0x10) == 0 || ((*(ushort *)(iVar4 + 0x74) & 0x14) == 0x10)))) {
    r_lld_adv_adv_data_set_hack
              (param_1,*(undefined1 *)(iVar4 + 0x28),*(undefined2 *)(iVar4 + 0x24),1,1);
    *(undefined2 *)(iVar4 + 0x24) = 0;
    adv_adv_data_need_to_set[param_1] = 0;
  }
  if ((adv_scan_rsp_data_need_to_set[param_1] != '\0') &&
     (((*(ushort *)(iVar4 + 0x74) & 0x12) == 2 || ((*(ushort *)(iVar4 + 0x74) & 0x14) == 0x10)))) {
    r_lld_adv_scan_rsp_data_set_hack
              (param_1,*(undefined1 *)(iVar4 + 0x2a),*(undefined2 *)(iVar4 + 0x26),1,1);
    *(undefined2 *)(iVar4 + 0x26) = 0;
    adv_scan_rsp_data_need_to_set[param_1] = 0;
  }
  r_lld_adv_frm_isr(param_1,param_2,param_3);
  if ((iVar4 != 0) && (bVar3)) {
    g_adv_delay_dis = '\0';
    *(undefined4 *)(iVar4 + 100) = unaff_s5;
  }
  return;
}

