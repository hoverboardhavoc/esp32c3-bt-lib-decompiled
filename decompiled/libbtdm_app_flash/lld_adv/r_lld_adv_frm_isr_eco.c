/*
 * Last changed at upstream commit aaf54a5f7e122db70b4a7ff02d2617858d43f649
 * https://github.com/espressif/esp32c3-bt-lib/commit/aaf54a5f7e122db70b4a7ff02d2617858d43f649
 * Upstream date: 2025-03-20 20:31:24 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(d74042a8)
 * Source: libbtdm_app_flash -> lld_adv.o -> r_lld_adv_frm_isr_eco
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_adv_frm_isr_eco(int param_1,undefined4 param_2,int param_3)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint unaff_s3;
  
  iVar2 = *(int *)(&lld_adv_env + param_1 * 4);
  bVar1 = false;
  if (iVar2 == 0) goto _L926;
  uVar5 = *(uint *)(iVar2 + 100);
  if ((uVar5 < 0x20) && (g_adv_delay_dis == '\0')) {
    bVar1 = true;
    if (param_3 == 0) goto _L936;
  }
  else {
    bVar1 = false;
    if (param_3 != 0) goto _L926;
    bVar1 = false;
_L936:
    if (g_ble_ext_config != '\0') {
      DAT_00015e7c = DAT_00015e7c + 1;
    }
    if (!bVar1) goto _L926;
  }
  g_adv_delay_dis = '\x01';
  uVar3 = (**(code **)(_r_osi_funcs_p + 0x88))(*(code **)(_r_osi_funcs_p + 0x88));
  uVar3 = uVar3 % 9;
  iVar4 = uVar3 << 1;
  if (*(char *)(iVar2 + 0x95) != '\0') {
    if (uVar3 == 0) {
      iVar4 = 1;
    }
    else if (uVar3 == 8) {
      iVar4 = 0xf;
    }
  }
  bVar1 = true;
  *(uint *)(iVar2 + 100) = (uint)(iVar4 + *(int *)(iVar2 + 100) * 2) >> 1;
  unaff_s3 = uVar5;
_L926:
  if ((adv_adv_data_need_to_set[param_1] != '\0') &&
     (((*(ushort *)(iVar2 + 0x74) & 0x10) == 0 || ((*(ushort *)(iVar2 + 0x74) & 0x14) == 0x10)))) {
    r_lld_adv_adv_data_set(param_1,*(undefined1 *)(iVar2 + 0x28),*(undefined2 *)(iVar2 + 0x24),1,1);
    *(undefined2 *)(iVar2 + 0x24) = 0;
    adv_adv_data_need_to_set[param_1] = 0;
  }
  if ((adv_scan_rsp_data_need_to_set[param_1] != '\0') &&
     (((*(ushort *)(iVar2 + 0x74) & 0x12) == 2 || ((*(ushort *)(iVar2 + 0x74) & 0x14) == 0x10)))) {
    r_lld_adv_scan_rsp_data_set
              (param_1,*(undefined1 *)(iVar2 + 0x2a),*(undefined2 *)(iVar2 + 0x26),1,1);
    *(undefined2 *)(iVar2 + 0x26) = 0;
    adv_scan_rsp_data_need_to_set[param_1] = 0;
  }
  r_lld_adv_frm_isr(param_1,param_2,param_3);
  if ((iVar2 != 0) && (bVar1)) {
    g_adv_delay_dis = '\0';
    *(uint *)(iVar2 + 100) = unaff_s3;
  }
  return;
}

