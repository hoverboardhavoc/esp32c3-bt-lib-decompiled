/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app -> lld_adv.o -> r_lld_adv_end_hack
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_adv_end_hack(int param_1,int param_2,uint param_3)

{
  int iVar1;
  undefined1 *puVar2;
  int iVar3;
  code *pcVar4;
  
  iVar1 = *(int *)(&lld_adv_env + param_1 * 4);
  if (iVar1 != 0) {
    if ((((*(short *)(iVar1 + 0x24) != 0) && (*(short *)(iVar1 + 0x7e) != 0)) &&
        (*(short *)(iVar1 + 0x24) != *(short *)(iVar1 + 0x7e))) &&
       (((*(ushort *)(iVar1 + 0x74) & 0x10) == 0 || ((*(ushort *)(iVar1 + 0x74) & 0x14) == 0x10))))
    {
      iVar3 = (**(code **)(_r_osi_funcs_p + 0x6c))(*(code **)(_r_osi_funcs_p + 0x6c));
      if (iVar3 == 0) {
        r_ble_util_buf_adv_tx_free(*(undefined2 *)(iVar1 + 0x7e));
      }
      else {
        (**(code **)(_r_ip_funcs_p + 0xdc))
                  (*(undefined2 *)(iVar1 + 0x7e),*(code **)(_r_ip_funcs_p + 0xdc));
      }
    }
    if (((*(short *)(iVar1 + 0x26) != 0) && (*(short *)(iVar1 + 0x80) != 0)) &&
       ((*(short *)(iVar1 + 0x26) != *(short *)(iVar1 + 0x80) &&
        (((*(ushort *)(iVar1 + 0x74) & 0x12) == 2 || ((*(ushort *)(iVar1 + 0x74) & 0x14) == 0x10))))
       )) {
      iVar3 = (**(code **)(_r_osi_funcs_p + 0x6c))(*(code **)(_r_osi_funcs_p + 0x6c));
      if (iVar3 == 0) {
        pcVar4 = *(code **)(_r_ip_funcs_p + 0xd8);
      }
      else {
        pcVar4 = *(code **)(_r_ip_funcs_p + 0xdc);
      }
      (*pcVar4)(*(undefined2 *)(iVar1 + 0x80),pcVar4);
    }
  }
  iVar1 = *(int *)(&lld_adv_env + param_1 * 4);
  if (iVar1 != 0) {
    (**(code **)(_r_ip_funcs_p + 0x6b8))(iVar1,0,*(code **)(_r_ip_funcs_p + 0x6b8));
    if (*(char *)(iVar1 + 0x95) != '\0') {
      (**(code **)(_r_ip_funcs_p + 0x6b8))(iVar1 + 0x34,0,*(code **)(_r_ip_funcs_p + 0x6b8));
    }
    if ((*(ushort *)(iVar1 + 0x74) & 8) != 0) {
      (**(code **)(_r_ip_funcs_p + 0x724))(2,*(code **)(_r_ip_funcs_p + 0x724));
    }
    if (param_2 != 0) {
      puVar2 = (undefined1 *)
               (**(code **)(_r_modules_funcs_p + 200))
                         (0x207,0,0xff,0x3c,*(code **)(_r_modules_funcs_p + 200));
      *puVar2 = (char)param_1;
      puVar2[1] = (char)param_3;
      puVar2[0x35] = 0;
      iVar3 = _r_modules_funcs_p;
      if ((param_3 != 0) && (param_3 = 0, *(short *)(iVar1 + 0x78) != 0)) {
        param_3 = (uint)*(byte *)(iVar1 + 0x86);
      }
      puVar2[0x38] = (char)param_3;
      (**(code **)(iVar3 + 0xe0))(*(code **)(iVar3 + 0xe0));
    }
    (**(code **)(_r_modules_funcs_p + 0x110))
              (*(undefined4 *)(&lld_adv_env + param_1 * 4),*(code **)(_r_modules_funcs_p + 0x110));
    *(undefined4 *)(&lld_adv_env + param_1 * 4) = 0;
  }
  return;
}

