/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> hci_tl.o -> r_hci_cmd_reject
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_hci_cmd_reject(int param_1,undefined4 param_2,undefined1 param_3,undefined1 *param_4)

{
  uint uVar1;
  int iVar2;
  undefined1 *puVar3;
  undefined4 uVar4;
  void *__s1;
  undefined2 auStack_22 [7];
  
  if (param_1 == 0) {
    auStack_22[0] = 1;
_L56:
    uVar4 = 0x1101;
  }
  else {
    if (*(code **)(param_1 + 8) != (code *)0x0) {
      if (*(char *)(param_1 + 2) < '\0') {
        uVar1 = (**(code **)(param_1 + 8))(0,0,auStack_22,0);
        uVar1 = uVar1 & 0xff;
      }
      else {
        uVar1 = r_co_util_unpack(0,0,auStack_22,0xffff);
      }
      if (uVar1 != 0) {
        r_assert_param(param_2,"hci_tl.c",0x1bf);
        return;
      }
      __s1 = *(void **)(param_1 + 8);
      iVar2 = memcmp(__s1,&_LC1,2);
      if (iVar2 == 0) {
        puVar3 = (undefined1 *)r_ke_msg_alloc(0x1101,0,param_2);
        *puVar3 = param_3;
        puVar3[2] = *param_4;
        puVar3[3] = param_4[1];
        goto _L54;
      }
      iVar2 = memcmp(__s1,&_LC2,3);
      if (iVar2 == 0) {
        puVar3 = (undefined1 *)r_ke_msg_alloc(0x1101);
        *puVar3 = param_3;
        memcpy(puVar3 + 1,param_4,6);
        goto _L54;
      }
      goto _L56;
    }
    auStack_22[0] = 1;
    uVar4 = 0x1102;
  }
  puVar3 = (undefined1 *)r_ke_msg_alloc(uVar4,0,param_2,auStack_22[0]);
  *puVar3 = param_3;
_L54:
  r_hci_send_2_host(puVar3);
  return;
}

